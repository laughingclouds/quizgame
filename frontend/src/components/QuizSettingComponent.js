import { useEffect, useState } from "react";

import ModalWithClose from "./ModalWithCloseComponent";

import { ICONS } from "../icons";

export default function QuizSetting({ setCategoryId }) {
  const [isDisabled, setIsDisabled] = useState(false);
  const [categories, setCategories] = useState([]);

  useEffect(() => {
    fetch("/api/categories/all")
      .then((resp) => resp.json())
      .then((data) => {
        setCategories(data.categories);
      });
  }, []);

  return (
    <ModalWithClose id="quiz-setting">
      <p className="font-bold text-primary">Select a category</p>
      <form
        className="prose"
        onSubmit={(e) => {
          e.preventDefault();
          setIsDisabled(true);
          window.location.replace("/#quiz-start");
        }}
      >
        <ul className="list-none">
          {categories.map((category) => {
            return (
              <li key={category.ID} className="form-control">
                <label htmlFor={category.ID} className="label">
                  <span className="label-text">{category.Name}</span>

                  <input
                    id={category.ID}
                    name="categoryId"
                    type="radio"
                    value={category.ID}
                    onChange={(e) => {
                      setCategoryId(e.target.value);
                      console.log(e.target.value);
                    }}
                    disabled={isDisabled}
                    required
                    className="radio radio-primary"
                  />
                </label>
              </li>
            );
          })}
        </ul>
        <div className="flex justify-between">
          <button type="submit" className="btn btn-outline btn-primary">
            {ICONS.start}Start Quiz
          </button>

          <button type="reset" onClick={() => setIsDisabled(false)} className="btn btn-outline btn-primary">
            {ICONS.cog}Reset
          </button>
        </div>
      </form>
    </ModalWithClose>
  );
}
