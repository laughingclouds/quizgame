package api

import (
	"errors"
	"log"
	"net/http"
	"strconv"

	"github.com/gin-gonic/gin"
	"github.com/laughingclouds/quizgame/auth"
	"github.com/laughingclouds/quizgame/db"
	"github.com/laughingclouds/quizgame/models"
	"gorm.io/gorm"
)

func CalculateScore(c *gin.Context) {
	categoryId, _ := strconv.Atoi(c.PostForm("category"))

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

	// How to parse forms
	// https://stackoverflow.com/questions/39984575/gin-gonic-array-of-values-from-postform
	_ = c.Request.ParseForm()
	for strQuestionId, values := range c.Request.PostForm {
		if strQuestionId != "category" {
			optionId, err := strconv.Atoi(values[0])
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
	}
	c.JSON(http.StatusOK, gin.H{
		"success": true,
	})
}
