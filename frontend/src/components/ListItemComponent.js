/**List item with custom styling and optional tooltip */
export default function ListItem({
  key = undefined,
  hiddenText = null,
  children = null,
  onClick = undefined,
  className = "",
}) {
  let classes = "w-full text-left pl-9 hover:text-primary " + className;
  if (hiddenText != null) {
    classes += "tooltip tooltip-right tooltip-info ";
  }

  return (
    <li onClick={onClick} key={key} data-tip={hiddenText} className={classes}>
      {children}
    </li>
  );
}
