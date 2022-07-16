import "./App.css";
import { Route, Routes } from "react-router-dom";
import { useState, useEffect } from "react";

import Home from "./routes/home";
import Login from "./routes/login";
import Leaderboard from "./routes/leaderboard";

import getCookie from "./util";

export default function App() {
	const [session, setSession] = useState({
		inSession: false,
		user: "None",
		userId: "0",
	});

	useEffect(() => {
		const user = getCookie("user");
		const userId = getCookie("userId");
		if (user !== "None" && user !== "" && userId !== "0" && userId !== "") {
			setSession({
				inSession: true,
				user: user,
				userId: userId,
			});
		}
	}, []);

	return (
		<>
			<Routes>
				<Route path="/" element={<Home session={session} />} />
				<Route path="/login" element={<Login />} />
				<Route path="/leaderboard" element={<Leaderboard />} />
			</Routes>
		</>
	);
}
