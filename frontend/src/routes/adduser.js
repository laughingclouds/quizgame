import { ICONS } from "../icons";
import { Link } from "react-router-dom";

export default function Adduser() {
  return (
    <>
      <form action="/api/createuser" method="post">
        <div>
          <label htmlFor="username">Username</label>
          <input id="username" type="text" name="username" />
        </div>

        <div>
          <label htmlFor="password">Password</label>
          <input id="password" type="password" name="password" />
        </div>

        <div>
          <button type="submit">{ICONS.adduser} Add User</button>
          <Link to="/">{ICONS.home} Return Home</Link>
        </div>
      </form>
    </>
  );
}
