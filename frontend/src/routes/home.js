export default function Home({ session }) {
	let navList = [];
	if (session.inSession) {
		navList = [
			["Start", "/quiz/setting", -1],
			["Logout", "/logout", 0],
			...baseNavList,
		];
	} else {
		navList = [["Login", "/login", 0], ...baseNavList];
	}

	navList = navList.map((navItem) => {
		return (
			<li key={navItem[2]}>
				<a
					href={navItem[1]}
					className="block px-4 py-2 w-full hover:text-yellow-400 cursor-pointer"
				>
					{navItem[0]}
				</a>
			</li>
		);
	});

	return (
		<div className="max-w-lg">
			<nav className="bg-black rounded-lg border border-gray-200 w-48 text-white text-lg font-medium text-center">
				{navList}
			</nav>
		</div>
	);
}

// element when not logged in
const baseNavList = [
	["Leaderboard", "/leaderboard", 1],
	["New User", "/adduser", 2],
];
