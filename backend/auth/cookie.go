package auth

import (
	"net/http"

	"github.com/gin-gonic/gin"
)

func GetSessionCookies(c *gin.Context) (user string, uid string) {
	user, err := c.Cookie("user")
	if err != nil {
		user = "None"
	}

	uid, err = c.Cookie("userId")
	if err != nil {
		uid = "0"
	}

	return user, uid
}

func SetSessionCookies(c *gin.Context, user, userId string) {
	http.SetCookie(c.Writer, &http.Cookie{
		Name:     "user",
		Value:    user,
		Path:     "/",
		MaxAge:   0,
		SameSite: http.SameSiteNoneMode,
		Secure:   true,
		HttpOnly: false,
	})

	http.SetCookie(c.Writer, &http.Cookie{
		Name:     "userId",
		Value:    userId,
		Path:     "/",
		MaxAge:   0,
		SameSite: http.SameSiteNoneMode,
		Secure:   true,
		HttpOnly: false,
	})
	// c.SetCookie("user", user, 0, "/", ":3000", false, false)
	// c.SetCookie("userId", userId, 0, "/", "/", false, false)
}
