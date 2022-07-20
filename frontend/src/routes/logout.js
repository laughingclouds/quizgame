export default function handleLogout(setState) {
  return () => {
    fetch("/api/logout")
      .then((resp) => resp)
      .then(() => {
        setState({
          user: "None",
          userId: "0",
        });
      })
      .catch((reason) => {
        console.log(reason);
      });
  };
}
