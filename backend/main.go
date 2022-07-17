package main

import (
	"fmt"
	"log"
	"net/http"

	"github.com/gin-gonic/gin"
	"github.com/laughingclouds/quizgame/auth"
	"github.com/laughingclouds/quizgame/routes"
)

func main() {
	auth.UserSession.Start("None", "0")
	app := gin.Default()

	app.StaticFS("/static/", http.Dir("./static"))

	app.GET("/", index)
	app.GET("/leaderboard", index)
	app.GET("/login", index)
	app.GET("/quiz/setting", index)
	app.GET("/adduser", index)

	app.GET("/login/info.json", routes.LoginInfo)
	app.GET("/leaderboard.json", routes.LeaderboardData)

	app.GET("/logout", routes.Logout)
	app.POST("/login/authenticate", routes.LoginAuthenticate)
	app.POST("/adduser/create", routes.CreateUser)

	log.Fatal(app.Run(":8000"))
}

func index(c *gin.Context) {
	fmt.Println(auth.UserSession)
	c.File("index.html")
}
