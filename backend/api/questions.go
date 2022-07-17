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
	questions := []models.Question{}

	db.DB.Where("\"categoryId\" = ?", categoryId).Find(&questions)

	c.JSON(http.StatusOK, gin.H{
		"questions": questions,
	})
}
