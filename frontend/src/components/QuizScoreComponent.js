import { useEffect, useState } from "react";
import { ICONS } from "../icons";

import ModalWithClose from "./ModalWithCloseComponent";

export default function QuizScore() {
  const [categories, setCategories] = useState([]);
  const [state, setState] = useState({
    isShow: false,
    categoryId: -1,
  });

  const [score, setScore] = useState({
    score: 0,
    count: 0,
  });

  const [refreshScore, setRefreshScore] = useState(false);

  useEffect(() => {
    fetch("/api/score")
      .then((resp) => resp.json())
      .then((data) => {
        setScore({
          score: data.score,
          count: data.count,
        });
      });
  }, [refreshScore]);

  useEffect(() => {
    fetch("/api/categories/all")
      .then((resp) => resp.json())
      .then((data) => {
        setCategories(data.categories);
      });
  }, [score]);

  return (
    <>
      <ModalWithClose id="quiz-score" divClass="w-11/12 max-w-5xl prose">
        <div className="flex">
          <h1 className="pr-1">
            <span className="text-secondary">
              {ICONS.academiccap} Total Score!
            </span>

            <span>
              {" "}
              {score.score} / {score.count}
            </span>
          </h1>

          <button
            onClick={() => setRefreshScore(!refreshScore)}
            className="btn btn-ghost"
          >
            {ICONS.refresh}
          </button>
        </div>

        <ShowAnswers isShow={state.isShow} categoryId={state.categoryId} />

        <div className="flex justify-between">
          <button
            onClick={() => window.location.replace("/")}
            className="btn btn-outline btn-primary"
          >
            {ICONS.home}Return Home
          </button>
          <div className="form-control">
            <select
              onChange={(e) => {
                setState({
                  isShow: true,
                  categoryId: e.target.value,
                });
              }}
              className="select select-ghost"
            >
              <option disabled selected>
                {ICONS.academiccap}Show Answers
              </option>
              {categories.map((category) => {
                return (
                  <option key={category.ID} value={category.ID}>
                    {category.Name}
                  </option>
                );
              })}
            </select>
          </div>

          <button
            onClick={() => window.location.replace("/#quiz-setting  ")}
            className="btn btn-outline btn-primary"
          >
            {ICONS.start}Attempt more quizes
          </button>
        </div>
      </ModalWithClose>
    </>
  );
}

function ShowAnswers({ isShow, categoryId }) {
  const [questions, setQuestions] = useState([]);

  useEffect(() => {
    fetch(`/api/questions/${categoryId}/answered`)
      .then((resp) => resp.json())
      .then((data) => {
        setQuestions(data.questions);
      });
  }, [isShow, categoryId]);

  if (isShow) {
    return (
      <>
        <h4>{ICONS.lightbulb} Answers</h4>

        <ol>
          <QuestionList questions={questions} />
        </ol>
      </>
    );
  }
  return <></>;
}

function QuestionList({ questions }) {
  return questions.map((question) => {
    return (
      <li key={question.ID}>
        <span>{question.Text}</span>
        <div className="text-accent">{question.Answer.Text}</div>
      </li>
    );
  });
}
