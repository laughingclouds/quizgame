import { useEffect, useState } from "react";

export default function Leaderboard() {
	const [lbData, setLbData] = useState([]);
	useEffect(() => {
		fetch("/api/leaderboard")
			.then((resp) => resp.json())
			.then((data) => {
				setLbData(data.users);
			});
	}, []);

	const leaderboard = lbData.map((lbItem) => {
		return (
			<tr>
				<td>{lbItem.Name}</td>
				<td>{lbItem.Score}</td>
			</tr>
		);
	});
	return (
		<>
			<table>
				<thead>
					<th>Name</th>
					<th>Score</th>
				</thead>

				<tbody>{leaderboard}</tbody>
			</table>
      <a href="/">Return Home</a>
		</>
	);
}
