import { Route, Routes, Navigate } from "react-router-dom";

import Home from "./routes/home";
import QuizStart from "./routes/quiz/start";
import QuizScore from "./routes/quiz/score";

export default function App() {
  return (
    <>
      <Routes>
        <Route path="/" element={<Home />} />
        <Route path="/quiz">
          <Route path="score" element={<QuizScore />} />
          <Route path="start" element={<QuizStart />} />
        </Route>
        <Route path="*" element={<Navigate to="/" replace />} />
      </Routes>
    </>
  );
}
