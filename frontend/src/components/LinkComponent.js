export default function Link({
  key = undefined,
  href = "/",
  hiddenText = null,
  children = null,
  onClick = undefined,
  className = "",
}) {
  let classes = "link hover:text-primary " + className;
  if (hiddenText != null) {
    classes += "tooltip tooltip-right tooltip-info ";
  }

  return (
    <a
      href={href}
      onClick={onClick}
      key={key}
      data-tip={hiddenText}
      className={classes}
    >
      {children}
    </a>
  );
}
