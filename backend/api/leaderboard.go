package api

import (
	"net/http"

	"github.com/gin-gonic/gin"
	"github.com/laughingclouds/quizgame/db"
	"github.com/laughingclouds/quizgame/models"
)

func LeaderboardData(c *gin.Context) {
	users := []models.APIUser{}
	db.DB.Model(&models.User{}).Order("score DESC").Limit(5).Find(&users)

	c.JSON(http.StatusOK, gin.H{
		"users": users,
	})
}
