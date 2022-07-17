package db

import (
	"fmt"
	"log"
	"os"

	"gorm.io/driver/postgres"
	"gorm.io/gorm"
)

var DB *gorm.DB

// Open connect to database using gorm.Open(postgres.Open(dsn)).
//
// Uses following environment variables:
// QZ_HOSTNAME, QZ_USERNAME, QZ_PASSWORD, QZ_DBNAME.
//
// log.Fatal if error during gorm.Open().
//
// Meant to be run once in func main to create globally accessible connection
func Open() {
	dsn := fmt.Sprintf(
		"host=%s user=%s password=%s dbname=%s",
		os.Getenv("QZ_HOSTNAME"),
		os.Getenv("QZ_USERNAME"),
		os.Getenv("QZ_PASSWORD"),
		os.Getenv("QZ_DBNAME"),
	)

	var err error
	DB, err = gorm.Open(postgres.Open(dsn))

	if err != nil {
		log.Fatal(err)
	}

	log.Printf("Connected to host=%s db=%s\n", os.Getenv("QZ_HOSTNAME"), os.Getenv("QZ_DBNAME"))
}
