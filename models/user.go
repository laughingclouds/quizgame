package models

type User struct {
	ID       uint
	Name     string `gorm:"unique"`
	Password string `gorm:"not null;default:''"`
	Score    int    `gorm:"not null;default:0"`
}
