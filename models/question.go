package models

type Question struct {
	ID         uint
	CategoryId uint
	AnswerId   uint
	Option2Id  uint
	Option3Id  uint
	Option4Id  uint
	Text       string `gorm:"unique"`
}
