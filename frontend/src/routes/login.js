export default function Login() {
  return (
    <>
     <form action='/api/login' method='post'>
      <div>
        <label htmlFor='username'>Username</label>
        <input id='username' type='text' name='username' />
      </div>

      <div>
        <label htmlFor='password'>Password</label>
        <input id='password' type='password' name='password'/>
      </div>

      <button type='submit'>Login</button>
     </form>
    </>
  );
}