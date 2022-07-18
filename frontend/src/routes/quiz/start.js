import { useEffect, useState } from "react";
import { useSearchParams } from "react-router-dom";

export default function QuizStart() {
  const [questions, setQuestions] = useState([]);
  const [category, setCategory] = useState({
    ID: "0",
    Name: "None",
  });
  const [searchParams] = useSearchParams();

  const categoryId = searchParams.get("categoryId");

  useEffect(() => {
    fetch(`/api/categories/${categoryId}`)
      .then((resp) => resp.json())
      .then((data) => {
        setCategory(data.category);
      });

    fetch(`/api/questions/${categoryId}`)
      .then((resp) => resp.json())
      .then((data) => {
        setQuestions(data.questions);
      });
  }, []);

  return (
    <>
      <h1>{category.Name}</h1>
      <h3>Start!</h3>

      <form action="/api/calculatescore" method="post">
        <input name="category" value={category.ID} hidden readOnly />

        <ul>
          <QuestionList questions={questions} />
        </ul>

        <button type="submit">Submit</button>
      </form>
    </>
  );
}

function QuestionList({ questions }) {
  return questions.map((question) => {
    return (
      <li key={question.ID}>
        <span>{question.Text}</span>
        <ul>
          <OptionList question={question} />
        </ul>
      </li>
    );
  });
}

function OptionList({ question }) {
  const options = question.Options;

  return options.map((option) => {
    return (
      <li key={option.ID}>
        <input
          id={option.ID}
          type="radio"
          name={question.ID}
          value={option.ID}
          required
        />
        <label htmlFor={option.ID}>{option.Text}</label>
      </li>
    );
  });
}
