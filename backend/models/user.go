package models

type User struct {
	ID       uint
	Name     string `gorm:"unique"`
	Password string `gorm:"not null;default:''"`
	Score    int    `gorm:"not null;default:0"`
}

// gorm smart select field
// https://gorm.io/docs/advanced_query.html#Smart-Select-Fields
type APIUser struct {
	ID    uint
	Name  string `gorm:"unique"`
	Score int    `gorm:"not null;default:0"`
}

type Score struct {
	Score int
}
