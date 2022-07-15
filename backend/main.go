package main

import (
	"log"
	"net/http"

	"github.com/gin-gonic/gin"
)

func main() {
	app := gin.Default()
	app.LoadHTMLGlob("static/templates/*.tmpl")

	app.GET("/", home)

	app.StaticFile("/favicon.ico", "./static/images/favicon.svg")
	log.Fatal(app.Run())
}

func home(ctx *gin.Context) {
	ctx.HTML(http.StatusOK, "index.tmpl", gin.H{})
}
