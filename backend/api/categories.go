package api

import (
	"net/http"

	"github.com/gin-gonic/gin"
	"github.com/laughingclouds/quizgame/db"
	"github.com/laughingclouds/quizgame/models"
)

// AllCategories json response with list of categories
// excluding category 1 (which is "None")
func AllCategories(c *gin.Context) {
	categories := []models.Category{}
	db.DB.Order("id ASC").Offset(1).Find(&categories)
	c.JSON(http.StatusOK, gin.H{
		"categories": categories,
	})
}

// Category json data for a single category
//
// Handle /api/categories/:categoryId
func Category(c *gin.Context) {
	categoryId := c.Param("categoryId")

	category := models.Category{}
	db.DB.Where("id = ?", categoryId).First(&category)

	c.JSON(http.StatusOK, gin.H{
		"category": category,
	})
}
