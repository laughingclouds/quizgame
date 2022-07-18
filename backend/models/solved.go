package models

type Solved struct {
	UserId     uint `gorm:"column:userId"`
	QuestionId uint `gorm:"column:questionId"`
}
