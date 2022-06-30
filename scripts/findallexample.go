package scripts

import (
	"fmt"
	"log"
	"os"

	"github.com/laughingclouds/quizgame/models"
	"gorm.io/driver/postgres"
	"gorm.io/gorm"
)

func RunFindAll() {
	databaseURI := fmt.Sprintf(
		"host=%s user=%s password=%s dbname=%s",
		os.Getenv("QZ_HOSTNAME"),
		os.Getenv("QZ_USERNAME"),
		os.Getenv("QZ_PASSWORD"),
		os.Getenv("QZ_DBNAME"),
	)

	db, err := gorm.Open(postgres.Open(databaseURI), &gorm.Config{})
	if err != nil {
		log.Fatal(err)
	}
	categories := []models.Category{}
	options := []models.Option{}
	db.Find(&categories)
	db.Find(&options)

	for _, category := range categories {
		fmt.Println(category)
	}
	for _, option := range options {
		fmt.Println(option)
	}
}
