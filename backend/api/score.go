package api

import (
	"errors"
	"log"
	"net/http"

	"github.com/gin-gonic/gin"
	"github.com/laughingclouds/quizgame/auth"
	"github.com/laughingclouds/quizgame/db"
	"github.com/laughingclouds/quizgame/models"
	"gorm.io/gorm"
)

// Score score of currently logged in user
//
// Handle /api/score
func Score(c *gin.Context) {
	var count int64
	solveds := []models.Solved{}
	user := models.User{}
	db.DB.Model(&models.Question{}).Count(&count)
	err := db.DB.Where("id = ?", auth.UserSession.UserId()).First(&user).Error

	if errors.Is(err, gorm.ErrRecordNotFound) {
		c.JSON(http.StatusOK, gin.H{
			"score": 0,
		})
		return
	}

	err = db.DB.Where("\"userId\" = ?", auth.UserSession.UserId()).Find(&solveds).Error

	if !errors.Is(err, gorm.ErrRecordNotFound) {
		log.Println(err)
	}

	if user.Score != len(solveds) {
		user.Score = len(solveds)
		db.DB.Where("\"id\" = ?", auth.UserSession.UserId()).Save(&user)
	}

	c.JSON(http.StatusOK, gin.H{
		"score": user.Score,
		"count": count,
	})
}
