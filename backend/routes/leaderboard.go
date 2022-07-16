package routes

import (
	"net/http"

	"github.com/gin-gonic/gin"
)

func LeaderboardData(c *gin.Context) {
	// code to get top scores from db
	users := []user{
		{Id: 1, Name: "Hemant", Score: 5},
		{Id: 2, Name: "Dhoni", Score: 4},
		{Id: 3, Name: "Picaso", Score: 3},
		{Id: 4, Name: "Buddha", Score: 0},
	}
	c.JSON(http.StatusOK, gin.H{
		"users": users,
	})
}

type user struct {
	Id    int
	Name  string
	Score int
}
