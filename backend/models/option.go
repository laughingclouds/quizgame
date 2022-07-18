package models

import "github.com/laughingclouds/quizgame/db"

// Option represents an "option" or a choice for any quiz question
type Option struct {
	ID   uint   `gorm:"primaryKey"`
	Text string `gorm:"unique"`
}

// Option get one Option type from the db, based on its' id
//
// Assuming given id is valid
func OptionFromId(id uint) Option {
	option := Option{}
	db.DB.Where("id = ?", id).First(&option)
	return option
}
