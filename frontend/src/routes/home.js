import handleLogout from "./logout";
import React, { useState, useEffect, useRef } from "react";
import { ICONS } from "../icons";
import AboutQuizGame from "../components/AboutComponent";
import QuizSetting from "../components/QuizSettingComponent";
import ListItem from "../components/ListItemComponent";
import Link from "../components/LinkComponent";
import Login from "../components/LoginComponent";
import Leaderboard from "../components/LeaderboardComponent";
import AddUser from "../components/AddUserComponent";
import QuizStart from "./quiz/start";
import QuizScore from "./quiz/score";

export default function Home() {
  const [state, setState] = useState({
    user: undefined,
    userId: undefined,
  });

  useEffect(() => {
    document.title = "Quiz Game";
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

  if (state.user !== "None" && state.user !== undefined) {
    inSession = true;
  }

  return (
    <>
      <main className="prose flex flex-col items-center justify-center min-h-screen min-w-full">
        <header className="p-2">
          {inSession ? <h1>Welcome {state.user}!</h1> : <h1>Welcome!</h1>}
        </header>
        <main>
          <div className="max-w-xl">
            <nav className="hidden-object-nav bg-neutral-focus rounded-lg border border-secondary hover:border-accent-focus w-48 text-white text-lg font-medium align-middle">
              <ul className="list-none m-0 p-0">
                <Menu inSession={inSession} setState={setState} />
              </ul>
            </nav>
          </div>
        </main>

        <footer>
          <AboutQuizGame />
        </footer>
      </main>
    </>
  );
}

function Menu({ inSession = false, setState }) {
  // let categoryId = -1;
  // const setCategoryId = (newId) => {categoryId = newId}
  const [categoryId, setCategoryId] = useState(-1);
  return (
    <>
      {inSession ? (
        <>
          <ListItem hiddenText="Start the quiz">
            <Link href="#quiz-setting">{ICONS.start}Start</Link>
            <QuizSetting setCategoryId={setCategoryId} />

            <QuizStart categoryId={categoryId} setCategoryId={setCategoryId} />

            <QuizScore categoryId={categoryId} />
          </ListItem>

          <ListItem hiddenText="Add a new user to the database">
            <Link href="#adduser">{ICONS.adduser}New User</Link>
            <AddUser />
          </ListItem>

          <ListItem onClick={handleLogout(setState)}>
            <Link>{ICONS.logout}Logout</Link>
          </ListItem>
        </>
      ) : (
        <ListItem hiddenText="Login to save your progress">
          <Link href="#login">{ICONS.login}Login</Link>
          <Login />
        </ListItem>
      )}

      <ListItem hiddenText="Show users with top scores">
        <Link href="#leaderboard">{ICONS.leaderboard}Leaderboard</Link>
        <Leaderboard />
      </ListItem>
    </>
  );
}
