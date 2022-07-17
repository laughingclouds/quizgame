package auth

var UserSession Session

type Session struct {
	user   string
	userId string
}

func (s *Session) End() {
	s.user = "None"
	s.userId = "0"
}

func (s *Session) Start(user, userId string) {
	s.user = user
	s.userId = userId
}

func (s Session) User() string {
	return s.user
}

func (s Session) UserId() string {
	return s.userId
}
