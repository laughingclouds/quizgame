package models

type Question struct {
	ID         uint
	CategoryId uint   `gorm:"column:categoryId"`
	AnswerId   uint   `gorm:"column:answerId"`
	Option2Id  uint   `gorm:"column:option2Id"`
	Option3Id  uint   `gorm:"column:option3Id"`
	Option4Id  uint   `gorm:"column:option4Id"`
	Text       string `gorm:"unique"`
}
