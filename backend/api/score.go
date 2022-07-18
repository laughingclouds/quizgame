package api

import (
	"log"
	"net/http"

	"github.com/gin-gonic/gin"
	"github.com/laughingclouds/quizgame/db"
	"github.com/laughingclouds/quizgame/models"
)

// Score score of currently logged in user
//
// Handle /api/score
func Score(c *gin.Context) {
	score := models.Score{}
	err := db.DB.Model(models.User{}).Select("score").First(&score).Error

	if err != nil {
		log.Println("/api/score", err)
		score.Score = 0
	}

	c.JSON(http.StatusOK, gin.H{
		"score": score.Score,
	})
}
