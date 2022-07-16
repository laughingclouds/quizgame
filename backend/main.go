package main

import (
	"log"
	"net/http"

	"github.com/gin-gonic/gin"
	"github.com/laughingclouds/quizgame/auth"
	"github.com/laughingclouds/quizgame/routes"
)

func main() {
	app := gin.Default()

	app.StaticFS("/static/", http.Dir("./static"))

	app.Any("/", index)
	app.Any("/leaderboard", index)
	app.Any("/login", index)
	app.Any("/quiz/setting", index)

	app.POST("/login/verify", routes.LoginAuthenticate)
	app.Any("/login/info.json", routes.LoginInfo)
	app.Any("/logout", routes.Logout)
	app.POST("/adduser/create", routes.CreateUser)
	app.Any("/leaderboard.json", routes.LeaderboardData)

	app.Any("/setCookies", func(c *gin.Context) {
		auth.SetSessionCookies(c, "Hemant", "1")
		a, b := auth.GetSessionCookies(c)
		c.String(http.StatusOK, "%s %s", a, b)
	})

	log.Fatal(app.Run())
}

func index(c *gin.Context) {
	c.File("index.html")
}
