import { useState } from "react";
import { ICONS } from "../icons";

/** Return footer than contains information on the application */
export default function AboutQuizGame() {
  return (
    <>
      <div
        tabIndex="0"
        className="collapse mt-7 collapse-plus border border-base-300 bg-base-100 rounded-box"
      >
        <input type="checkbox" className="peer" />

        <div className="collapse-title">{ICONS.questionmark}About</div>

        <article className="collapse-content max-w-lg prose prose-default">
          {mainContent}
        </article>
      </div>
    </>
  );
}

const mainContent = (
  <>
    <p>
      Welcome to this quiz-game I've built for you! You can find the source in{" "}
      <a
        className="link link-primary"
        href="https://github.com/laughingclouds/quizgame"
        target="_blank"
      >
        this github repository
      </a>
      .
    </p>
    <p>
      This is a full stack application built using React.js, Gin framework and
      Tailwindcss. I hope you like it.
    </p>
    <p>Hover your mouse over any of the options to know what they do.</p>
  </>
);
