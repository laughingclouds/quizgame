import { useEffect, useState } from "react";
import { useSearchParams } from "react-router-dom";
import { ICONS } from "../../icons";

export default function QuizScore() {
  const [score, setScore] = useState({
    score: 0,
    count: 0,
  });
  const [questions, setQuestions] = useState([]);
  const [searchParams] = useSearchParams();
  const categoryId = searchParams.get("category");

  useEffect(() => {
    document.title = "Score";
    fetch("/api/score")
      .then((resp) => resp.json())
      .then((data) => {
        setScore({
          score: data.score,
          count: data.count,
        });
      });

    fetch(`/api/questions/${categoryId}/answered`)
      .then((resp) => resp.json())
      .then((data) => {
        setQuestions(data.questions);
      });
  }, []);

  return (
    <>
      <h1>{ICONS.academiccap} Total Score! {score.score} / {score.count}</h1>

      <h4>{ICONS.lightbulb} Answers</h4>

      <ol>
        <QuestionList questions={questions} />
      </ol>

      <a href="/">{ICONS.home} Return Home</a>
    </>
  );
}

function QuestionList({ questions }) {
  return questions.map((question) => {
    return (
      <li key={question.ID}>
        <span>{question.Text}</span>
        <div>{question.Answer.Text}</div>
      </li>
    );
  });
}
