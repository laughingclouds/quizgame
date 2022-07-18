package api

import (
	"errors"
	"net/http"
	"strings"

	"github.com/gin-gonic/gin"
	"github.com/laughingclouds/quizgame/auth"
	"github.com/laughingclouds/quizgame/db"
	"github.com/laughingclouds/quizgame/models"
	"gorm.io/gorm"
)

// Login authenticates credentials entered in /login.
// Redirects to "/" after setting session cookies
func Login(c *gin.Context) {
	name, _ := c.GetPostForm("username")
	password, _ := c.GetPostForm("password")

	name = strings.TrimSpace(name)
	password = strings.TrimSpace(password)

	if name == "" {
		c.Redirect(http.StatusSeeOther, "/login")
		return
	}

	// TODO get user id from data-base
	user := models.User{}
	err := db.DB.Where("name = ? AND password = ?", name, password).First(&user).Error

	if errors.Is(err, gorm.ErrRecordNotFound) {
		c.Redirect(http.StatusSeeOther, "/login")

	} else {
		auth.UserSession.Start(name, user.ID)
		c.Redirect(http.StatusSeeOther, "/")

	}
}

// SessionInfo return user session data (username, user id)
//
// Handle /api/sessioninfo
func SessionInfo(c *gin.Context) {
	c.JSON(http.StatusOK, gin.H{
		"user":   auth.UserSession.User(),
		"userId": auth.UserSession.UserId(),
	})
}
