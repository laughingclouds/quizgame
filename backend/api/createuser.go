package api

import (
	"net/http"
	"strings"

	"github.com/gin-gonic/gin"
	"github.com/laughingclouds/quizgame/db"
	"github.com/laughingclouds/quizgame/models"
)

// CreateUser checks credentials and redirects to "/" after creating new user.
// If credentials are not okay, redirect to "/adduser"
//
// Handle "/api/createuser"
func CreateUser(c *gin.Context) {
	name, _ := c.GetPostForm("username")
	password, _ := c.GetPostForm("password")

	name = strings.TrimSpace(name)
	password = strings.TrimSpace(password)

	if name == "" {
		c.Redirect(http.StatusSeeOther, "/adduser")
		return
	}

	user := models.User{
		Name:     name,
		Password: password,
		Score:    0,
	}

	err := db.DB.Create(&user).Error

	if err != nil {
		c.Redirect(http.StatusSeeOther, "/adduser")

	} else {
		c.Redirect(http.StatusSeeOther, "/")
	}
}
