import "./App.css";
import { Route, Routes } from "react-router-dom";

import Home from "./routes/home";
import Login from "./routes/login";
import Leaderboard from "./routes/leaderboard";
import Adduser from "./routes/adduser";
import QuizStart from "./routes/quiz/start";
import QuizSetting from "./routes/quiz/setting";

export default function App() {
	return (
		<>
			<Routes>
				<Route path="/" element={<Home/>} />
				<Route path="/login" element={<Login />} />
				<Route path="/adduser" element={<Adduser />} />
				<Route path="/quiz">
					<Route path="setting" element={<QuizSetting />} />
					<Route path="start" element={<QuizStart />} />
				</Route>
				<Route path="/leaderboard" element={<Leaderboard />} />
			</Routes>
		</>
	);
}
