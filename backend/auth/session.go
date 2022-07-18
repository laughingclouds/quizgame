package auth

var UserSession Session

type Session struct {
	user   string
	userId uint
}

func (s *Session) End() {
	s.user = "None"
	s.userId = 0
}

func (s *Session) Start(user string, userId uint) {
	s.user = user
	s.userId = userId
}

func (s Session) User() string {
	return s.user
}

func (s Session) UserId() uint {
	return s.userId
}
