import handleLogout from "./logout";
import { useState, useEffect } from "react";
import { Link } from "react-router-dom";

// element when not logged in
const baseNavList = [
  ["Leaderboard", "/leaderboard", 1],
  ["New User", "/adduser", 2],
];

export default function Home() {
  const [state, setState] = useState({
    user: undefined,
    userId: undefined,
  });

  useEffect(() => {
    fetch("/api/sessioninfo")
      .then((resp) => resp.json())
      .then((jsonData) => {
        setState({
          user: jsonData.user,
          userId: jsonData.userId,
        });
      });
  }, []);

  let inSession = false;

  let navList = [];
  if (state.user !== "None" && state.user !== undefined) {
    inSession = true;

    navList = [["Start", "/quiz/setting", 0], ...baseNavList];
  } else {
    navList = [["Login", "/login", 0], ...baseNavList];
  }

  return (
    <>
      <main>
        <header>
          {inSession ? <h1>Welcome {state.user}!</h1> : <h1>Welcome!</h1>}
        </header>

        <main>
          <div className="max-w-lg">
            <nav className="bg-black rounded-lg border border-gray-200 w-48 text-white text-lg font-medium text-center">
              <ul>
                {navList.map((navItem) => {
                  return (
                    <li key={navItem[2]}>
                      <Link
                        to={navItem[1]}
                        className="block px-4 py-2 w-full hover:text-yellow-400 cursor-pointer"
                      >
                        {navItem[0]}
                      </Link>
                    </li>
                  );
                })}

                {inSession ? (
                  <li
                    onClick={handleLogout(setState)}
                    className="block px-4 py-2 w-full hover:text-yellow-400 cursor-pointer"
                  >
                    Logout
                  </li>
                ) : (
                  <></>
                )}
              </ul>
            </nav>
          </div>
        </main>

        <footer>
          <article>
            <h2>About</h2>
            <p>
              Welcome to this quiz-game I've built for you! You can find the
              source in
              <a
                href="https://github.com/laughingclouds/quizgame"
                target="_blank"
              >
                this github repository
              </a>
              .
            </p>
            <p>
              This is a full stack application built using React.js, Gin
              framework and Tailwindcss. I hope you like it.
            </p>
            <p>
              Hover your mouse over any of the options to know what they do.
            </p>
          </article>
        </footer>
      </main>
    </>
  );
}
