import { useEffect, useState } from "react";

import ModalWithClose from "./ModalWithCloseComponent";

import { ICONS } from "../icons"

export default function QuizSetting() {
  const [categories, setCategories] = useState([]);

  useEffect(() => {
    document.title = "Setting";
    fetch("/api/categories/all")
      .then((resp) => resp.json())
      .then((data) => {
        setCategories(data.categories);
      });
  }, []);
  return (
    <ModalWithClose id="quiz-setting">
      <p className="font-bold text-primary">Select a category</p>
      <form action="/quiz/start" method="get" className="prose">
        <ul className="list-none">
          <CategoryList categories={categories} />
        </ul>
        <button type="submit" className="btn btn-outline btn-primary">{ICONS.start} Start Quiz</button>
      </form>
    </ModalWithClose>
  );
}

function CategoryList({ categories }) {
  return categories.map((category) => {
    return (
      <li key={category.ID} className="form-control">
        <label htmlFor={category.ID} className="label">
          <span className="label-text">{category.Name}</span>

          <input
            id={category.ID}
            name="categoryId"
            type="radio"
            value={category.ID}
            required
            className="radio radio-primary"
          />
        </label>
      </li>
    );
  });
}
