import FormInput from "./FormInputComponent";

/**Basic form for login and logout.
 * Sends only post.
 * Custom submit button to be inputted as child. If not given,
 * generic "submit" will be used.
 */

export default function LoginLogoutForm({
  id = "",
  className = "",
  action = undefined,
  children = null,
}) {
  if (children === null) {
    children = (
      <button className="btn btn-primary" type="submit">
        Submit
      </button>
    );
  }
  return (
    <>
      <form id={id} action={action} method="post" className={className}>
        <FormInput id="username" type="text" name="username" placeholder="Enter username">
          Username
        </FormInput>

        <FormInput id="password" type="password" name="password" placeholder="Enter password">
          Password
        </FormInput>

        <div>{children}</div>
      </form>
    </>
  );
}
