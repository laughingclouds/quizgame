export default function Logout({ state }) {
  console.log("Before Logout:", state);
	return (
		<>
			<h1>You Have Been Logged Out</h1>
      <a href="/">Return Home</a>
		</>
	);
}
