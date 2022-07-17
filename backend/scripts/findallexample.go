package scripts

import (
	"fmt"

	"github.com/laughingclouds/quizgame/db"
	"github.com/laughingclouds/quizgame/models"
)

func RunFindAll() {
	categories := []models.Category{}
	options := []models.Option{}
	db.DB.Find(&categories)
	db.DB.Find(&options)

	for _, category := range categories {
		fmt.Println(category)
	}
	for _, option := range options {
		fmt.Println(option)
	}
}
