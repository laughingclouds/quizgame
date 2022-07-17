export default function handleLogout(setState) {
	return () => {
		fetch("/api/logout")
			.then((resp) => resp.json())
			.then((data) => {
				setState({
					user: "None",
					userId: "0",
				});
			});
	};
}
