package main

import (
	"log"
	"net/http"

	"github.com/gin-gonic/gin"
	"github.com/laughingclouds/quizgame/api"
	"github.com/laughingclouds/quizgame/auth"
	"github.com/laughingclouds/quizgame/db"
)

func main() {
	db.Open()
	auth.UserSession.Start("None", "0")
	server := gin.Default()

	server.StaticFS("/static/", http.Dir("./static"))

	// For front-end
	server.GET("/", index)
	server.GET("/quiz/setting", index)
	server.GET("/quiz/start", index)
	server.GET("/quiz/score", index)
	server.GET("/login", index)
	server.GET("/leaderboard", index)
	server.GET("/adduser", index)

	// Both
	server.GET("/api/logout", api.Logout)

	// For backend
	server.POST("/api/createuser", api.CreateUser)
	server.POST("/api/login", api.Login)
	// json responses
	server.GET("/api/sessioninfo", api.SessionInfo)
	server.GET("/api/leaderboard", api.LeaderboardData)
	server.GET("/api/categories/all", api.AllCategories)
	server.GET("/api/categories/:categoryId", api.Category)
	server.GET("/api/questions/:categoryId", api.Question)

	log.Fatal(server.Run())
}

func index(c *gin.Context) {
	log.Printf("Session: %v", auth.UserSession)
	c.File("index.html")
}
