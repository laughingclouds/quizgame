package routes

import (
	"net/http"

	"github.com/gin-gonic/gin"
	"github.com/laughingclouds/quizgame/auth"
)

// LoginAuthenticate authenticates credentials entered in /login.
// Redirects to "/" after setting session cookies
func LoginAuthenticate(c *gin.Context) {
	// code to set cookie then redirect if credentials are okay
	c.Redirect(http.StatusSeeOther, "/")
}

// LoginInfo returns a json response containing cookie data
func LoginInfo(c *gin.Context) {
	c.Header("Access-Control-Allow-Origin", "*")
	user, uid := auth.GetSessionCookies(c)
	c.JSON(http.StatusOK, gin.H{
		"user":   user,
		"userId": uid,
	})
}
