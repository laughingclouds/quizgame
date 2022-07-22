import { useEffect, useState } from "react";
import { ICONS } from "../icons";

import ModalWithClose from "./ModalWithCloseComponent";

export default function QuizStart({ categoryId, setCategoryId }) {
  const [questions, setQuestions] = useState([]);
  const [category, setCategory] = useState({
    ID: "-1",
    Name: "None",
  });

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
  }, [categoryId]);

  return (
    <>
      <ModalWithClose id="quiz-start" divClass="w-11/12 max-w-5xl min-h-screen">
        <h1>Start!</h1>
        <h2>{category.Name}</h2>

        <form
          action="/api/calculatescore"
          method="post"
          onSubmit={(e) => {
            e.preventDefault();
            let postData = `${categoryId}|`;            

            for (const [key, value] of new FormData(e.target)) {
              postData += key + `:${value}-`;
            }

            console.log(postData);

            fetch("/api/calculatescore", {
              method: "POST",
              body: postData,
            })
              .then((res) => res.text())
              .then(() => window.location.replace("/#quiz-score"));
          }}
        >
          <ol>
            <QuestionList questions={questions} />
          </ol>

          <div className="flex justify-between">
            <button
              type="submit"
              className="btn btn-sm btn-outline btn-primary"
            >
              Submit
            </button>

            <button
              type="button"
              onClick={() => {
                setCategoryId(-1);
                window.location.replace("/#quiz-setting");
              }}
              className="btn btn-sm btn-outline btn-primary"
            >
              {ICONS.start}Go Back
            </button>
          </div>
        </form>
      </ModalWithClose>
    </>
  );
}

function QuestionList({ questions }) {
  return questions.map((question) => {
    return (
      <li key={question.ID}>
        <span>{question.Text}</span>
        <ol>
          <OptionList question={question} />
        </ol>
      </li>
    );
  });
}

function OptionList({ question }) {
  const options = question.Options;

  return options.map((option) => {
    return (
      <li key={option.ID} className="form-control">
        <label htmlFor={option.ID} className="label cursor-pointer">
          <span className="label-text hover:text-accent">{option.Text}</span>

          <input
            id={option.ID}
            type="radio"
            name={question.ID}
            value={option.ID}
            required
            className="radio radio-primary"
          />
        </label>
      </li>
    );
  });
}
