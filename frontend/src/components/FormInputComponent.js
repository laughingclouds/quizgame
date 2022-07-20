/**Simple input component with label */

export default function FormInput({
  id = "",
  type = "",
  name = "",
  children = null,
  placeholder = "",
}) {
  return (
    <>
      <div className="form-control">
        <label htmlFor={id} className="label">
          {children}
        </label>
        <input
          id={id}
          type={type}
          name={name}
          placeholder={placeholder}
          className="input input-ghost input-lg input-secondary"
        />
      </div>
    </>
  );
}
