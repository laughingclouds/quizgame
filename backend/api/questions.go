package api

import (
	"net/http"

	"github.com/gin-gonic/gin"
	"github.com/laughingclouds/quizgame/db"
	"github.com/laughingclouds/quizgame/models"
)

// Questions json with questions
//
// Handle '/api/questions/:categoryId'
func Question(c *gin.Context) {
	categoryId := c.Param("categoryId")
	dbQuestions := GetAllQuestionsByCategoryId(categoryId)
	questions := []models.QuestionOption{}

	for _, dbQuestion := range dbQuestions {
		questions = append(questions, dbQuestion.QuestionOption())
	}

	c.JSON(http.StatusOK, gin.H{
		"questions": questions,
	})
}

// Answered json response of QuestionAnswer
//
// Handle '/api/questions/:categoryId/answered``
func Answered(c *gin.Context) {
	categoryId := c.Param("categoryId")
	dbQuestions := GetAllQuestionsByCategoryId(categoryId)
	questions := []models.QuestionAnswer{}

	for _, dbQuestion := range dbQuestions {
		questions = append(questions, dbQuestion.QuestionAnswer())
	}

	c.JSON(http.StatusOK, gin.H{
		"questions": questions,
	})
}

func GetAllQuestionsByCategoryId(categoryId string) []models.Question {
	dbQuestions := []models.Question{}

	db.DB.Where("\"categoryId\" = ?", categoryId).Find(&dbQuestions)
	return dbQuestions
}
