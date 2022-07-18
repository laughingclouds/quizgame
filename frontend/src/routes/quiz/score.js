import { useEffect, useState } from "react";
import { useSearchParams } from "react-router-dom";

export default function QuizScore() {
  const [score, setScore] = useState('');
  const [questions, setQuestions] = useState([]);
  const [searchParams] = useSearchParams();
  const categoryId = searchParams.get("category");
  
  useEffect(() => {
    fetch("/api/score")
      .then((resp) => resp.json())
      .then((data) => {
        setScore(data.score);
      });

    fetch(`/api/questions/${categoryId}/answered`)
      .then((resp) => resp.json())
      .then((data) => {
        setQuestions(data.questions);
      });
  }, []);

  return (
    <>
      <h1>Total Score! {score}</h1>

      <h4>Answers</h4>

      <ul>
        <QuestionList questions={questions} />
      </ul>

      <a href="/">Return Home</a>
    </>
  );
}

function QuestionList({ questions }) {
  return questions.map((question) => {
    return (
      <li key={question.ID}>
        <span>{question.Text}</span>
        <span>{question.Answer.Text}</span>
      </li>
    );
  });
}
