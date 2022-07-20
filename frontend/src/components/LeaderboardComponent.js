import { useEffect, useState } from "react";
import ModalWithClose from "./ModalWithCloseComponent";

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
      <tr key={lbItem.ID}>
        <td>{lbItem.Name}</td>
        <td>{lbItem.Score}</td>
      </tr>
    );
  });
  return (
    <>
      <ModalWithClose id="leaderboard">
        <table>
          <thead>
            <tr>
              <th>Name</th>
              <th>Score</th>
            </tr>
          </thead>

          <tbody>{leaderboard}</tbody>
        </table>
      </ModalWithClose>
    </>
  );
}
