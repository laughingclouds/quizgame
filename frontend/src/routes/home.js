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
      {inSession ? (
        <header>
          <h3>Welcome! {state.user}</h3>
        </header>
      ) : (
        <></>
      )}
      <div className="max-w-lg">
        <nav className="bg-black rounded-lg border border-gray-200 w-48 text-white text-lg font-medium text-center">
          <ol>
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
          </ol>
        </nav>
      </div>
    </>
  );
}
