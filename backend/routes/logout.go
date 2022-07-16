package routes

import (
	"net/http"

	"github.com/gin-gonic/gin"
	"github.com/laughingclouds/quizgame/auth"
)

func Logout(c *gin.Context) {
	auth.SetSessionCookies(c, "None", "0")
	c.Redirect(http.StatusMovedPermanently, "/")
}
