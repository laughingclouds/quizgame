package api

import (
	"net/http"

	"github.com/gin-gonic/gin"
	"github.com/laughingclouds/quizgame/auth"
)

func Logout(c *gin.Context) {
	auth.UserSession.End()

	c.JSON(http.StatusOK, gin.H{
		"success": true,
	})
}
