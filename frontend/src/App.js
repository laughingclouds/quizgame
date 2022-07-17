import "./App.css";
import { Route, Routes } from "react-router-dom";
import { useEffect, useState } from "react";

import Home from "./routes/home";
import Login from "./routes/login";
import Leaderboard from "./routes/leaderboard";
import Logout from "./routes/logout";

export default function App() {
	const [state, setState] = useState({
		user: undefined,
		userId: undefined,
	});

	useEffect(() => {
		fetch("/login/info.json")
			.then((resp) => resp.json())
			.then((jsonData) => {
				setState({
					user: jsonData.user,
					userId: jsonData.userId,
				});
				console.log("useEffect:", state);
			});
	}, []);

	return (
		<>
			<Routes>
				<Route path="/" element={<Home state={state} />} />
				<Route path="/login" element={<Login />} />
        <Route path="/logout" element={<Logout state={state} setState={setState} />} />
				<Route path="/leaderboard" element={<Leaderboard />} />
			</Routes>
		</>
	);
}
