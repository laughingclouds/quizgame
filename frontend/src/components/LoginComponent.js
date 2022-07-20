import { ICONS } from "../icons";
import LoginLogoutForm from "./LoginLogoutFormComponent";
import ModalWithClose from "./ModalWithCloseComponent";

export default function Login() {
  return (
    <>
      <ModalWithClose id="login" divClass="h-96">
        <LoginLogoutForm
          action="/api/login"
          className="prose flex flex-col justify-between min-h-full"
        >
          <button className="btn btn-sm btn-primary" type="submit">
            {ICONS.login}Login
          </button>
        </LoginLogoutForm>
      </ModalWithClose>
    </>
  );
}
