package api

import (
	"errors"
	"io/ioutil"
	"log"
	"net/http"
	"strconv"
	"strings"

	"github.com/gin-gonic/gin"
	"github.com/laughingclouds/quizgame/auth"
	"github.com/laughingclouds/quizgame/db"
	"github.com/laughingclouds/quizgame/models"
	"gorm.io/gorm"
)

type QuizResponse struct {
	Category string
	Answers  map[string]string
}

/**Format of data it works on-
categoryId|questionId:answerId-questionId:answerId-
*/
func (qr *QuizResponse) FromString(strResponse string) {
	response := strings.Split(strResponse, "|")
	qr.Category = response[0]

	answers := response[1]
	if qr.Answers == nil {
		qr.Answers = map[string]string{}
	}

	for _, pairStr := range strings.Split(answers, "-") {
		if pairStr == "" {
			return
		}
		pairs := strings.Split(pairStr, ":")
		qr.Answers[pairs[0]] = pairs[1]
	}
}

func CalculateScore(c *gin.Context) {
	byteData, _ := ioutil.ReadAll(c.Request.Body)
	data := string(byteData)
	quizResponse := QuizResponse{}
	quizResponse.FromString(data)

	categoryId, _ := strconv.Atoi(quizResponse.Category)

	user := models.User{}
	err := db.DB.Where("id = ?", auth.UserSession.UserId()).First(&user).Error
	// user probably not logged in
	if err != nil {
		log.Println(err)
		c.JSON(http.StatusBadRequest, gin.H{
			"success": false,
			"error":   "User probably not logged in",
		})
		return
	}

	questions := []models.Question{}
	questionsMap := make(map[uint]models.Question)
	db.DB.Where("\"categoryId\" = ?", categoryId).Find(&questions)

	for _, question := range questions {
		questionsMap[question.ID] = question
	}

	for strQuestionId, value := range quizResponse.Answers {
		optionId, err := strconv.Atoi(value)
		// it would be weird if value is not a number as it represents optionId
		if err != nil {
			log.Fatal(err)
		}

		formQuestionId, _ := strconv.Atoi(strQuestionId)

		if questionsMap[uint(formQuestionId)].AnswerId == uint(optionId) {
			solved := models.Solved{}
			err := db.DB.Where("\"userId\" = ? AND \"questionId\" = ?", auth.UserSession.UserId(), formQuestionId).First(&solved).Error

			if errors.Is(err, gorm.ErrRecordNotFound) {
				user.Score++
				solved = models.Solved{
					UserId:     auth.UserSession.UserId(),
					QuestionId: uint(formQuestionId),
				}
				db.DB.Create(&solved)
				db.DB.Model(&user).Where("id = ?", user.ID).Update("score", user.Score)
			}
		}
	}
	c.JSON(http.StatusOK, gin.H{
		"success": true,
	})
}
