package models

type Solved struct {
	UserId     uint `gorm:"not null"`
	QuestionId uint `gorm:"not null"`
}
