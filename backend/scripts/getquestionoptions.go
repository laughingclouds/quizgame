package scripts

import (
	"encoding/json"
	"fmt"

	"github.com/laughingclouds/quizgame/db"
	"github.com/laughingclouds/quizgame/models"
)

type Users struct {
	ID         int64            `gorm:"id" json:"id"`
	Name       int64            `gorm:"name" json:"name"`
	UserTypeID int              `gorm:"column:user_type_id" json:"-"`
	UserType   BusinnesUserType `gorm:"foreignKey:id;references:user_type_id" json:"user_type"`
	LanguageID int64            `gorm:"column:language_id" json:"-"`
	Language   Language         `gorm:"foreignKey:ID;references:LanguageID" json:"language"`
}

type BusinnesUserType struct {
	ID          int64           `gorm:"id" json:"id"`
	Description json.RawMessage `gorm:"description" json:"description"`
}

type Language struct {
	ID          int64           `gorm:"id" json:"id"`
	Description json.RawMessage `gorm:"description" json:"description"`
}

// Get []db.Question{} based on category ID
func RunGetQuestionOptions() {
	// dbQuestions := []db.QuestionOption{}
	dbQuestions := []models.Question{}
	questionOptions := []models.QuestionOption{}

	db.DB.Where("\"categoryId\" = 2").Find(&dbQuestions)

	for _, dbQuestion := range dbQuestions {
		questionOptions = append(questionOptions, dbQuestion.QuestionOption())
	}

	for _, questionOption := range questionOptions {
		fmt.Println(questionOption)
	}
}
