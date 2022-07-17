package routes

import (
	"fmt"

	"github.com/gin-gonic/gin"
	"github.com/laughingclouds/quizgame/auth"
)

func Logout(c *gin.Context) {
	fmt.Println(auth.UserSession)
	auth.UserSession.End()
	fmt.Println(auth.UserSession)

	c.File("index.html")
}
