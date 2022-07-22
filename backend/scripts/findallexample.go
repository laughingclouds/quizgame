package scripts

import (
	"log"

	"github.com/laughingclouds/quizgame/db"
	"github.com/laughingclouds/quizgame/models"
)

func RunFindall() {
	questions := []models.Question{}
	db.DB.Where("\"categoryId\" = ?", 2).Find(&questions)
	log.Println(questions)
}
