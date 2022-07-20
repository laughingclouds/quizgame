import LoginLogoutForm from "./LoginLogoutFormComponent";
import ModalWithClose from "./ModalWithCloseComponent";

import { ICONS } from "../icons";

export default function AddUser() {
  return (
    <ModalWithClose id="adduser" divClass="h-96">
      <LoginLogoutForm
        action="/api/createuser"
        className="prose flex flex-col justify-between min-h-full"
      >
        <button className="btn btn-sm btn-primary" type="submit">
          {ICONS.adduser}Add User
        </button>
      </LoginLogoutForm>
    </ModalWithClose>
  );
}
