package models

// Option represents an "option" or a choice for any quiz question
type Option struct {
	ID   uint   `gorm:"primaryKey"`
	Text string `gorm:"unique"`
}
