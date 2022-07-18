package models

import "math/rand"

type Question struct {
	ID         uint
	CategoryId uint   `gorm:"column:categoryId"`
	AnswerId   uint   `gorm:"column:answerId"`
	Option2Id  uint   `gorm:"column:option2Id"`
	Option3Id  uint   `gorm:"column:option3Id"`
	Option4Id  uint   `gorm:"column:option4Id"`
	Text       string `gorm:"unique"`
}

type QuestionOption struct {
	ID      uint
	Options []Option
	Text    string
}

type QuestionAnswer struct {
	ID     uint
	Answer Option
	Text   string
}

func (q *Question) QuestionAnswer() QuestionAnswer {
	option := OptionFromId(q.AnswerId)

	return QuestionAnswer{
		ID:     q.ID,
		Answer: option,
		Text:   q.Text,
	}
}

func (q *Question) QuestionOption() QuestionOption {
	options := []Option{}

	for _, optionId := range q.OptionIds() {
		options = append(options, OptionFromId(optionId))
	}

	rand.Shuffle(4, func(i, j int) {
		options[i], options[j] = options[j], options[i]
	})

	return QuestionOption{
		ID:      q.ID,
		Options: options,
		Text:    q.Text,
	}
}

func (q *Question) OptionIds() []uint {
	return []uint{q.AnswerId, q.Option2Id, q.Option3Id, q.Option4Id}
}
