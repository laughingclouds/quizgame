package scripts

import (
	"fmt"

	"github.com/laughingclouds/quizgame/db"
	"github.com/laughingclouds/quizgame/models"
)

func RunReturnLeaderboard() {
	users := []models.APIUser{}
	db.DB.Model(&models.User{}).Order("score DESC").Limit(5).Find(&users)

	for _, user := range users {
		fmt.Println(user)
	}
}
