package routes

import (
	"net/http"
	"strings"

	"github.com/gin-gonic/gin"
	"github.com/laughingclouds/quizgame/auth"
)

// LoginAuthenticate authenticates credentials entered in /login.
// Redirects to "/" after setting session cookies
func LoginAuthenticate(c *gin.Context) {
	username, _ := c.GetPostForm("username")
	// password, _ := c.GetPostForm("password")

	if username == "" {
		c.Redirect(http.StatusSeeOther, "/login")
		return
	}
	// TODO get user id from data-base
	// code to set cookie then redirect if credentials are okay
	auth.UserSession.Start(strings.TrimSpace(username), strings.TrimSpace("-1"))

	c.Redirect(http.StatusSeeOther, "/")
}

// LoginInfo returns a json response containing cookie data
func LoginInfo(c *gin.Context) {
	c.JSON(http.StatusOK, gin.H{
		"user":   auth.UserSession.User(),
		"userId": auth.UserSession.UserId(),
	})
}
