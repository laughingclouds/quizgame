import { ICONS } from "../icons";

/**change mox size using divClass */
export default function ModalWithClose({ id, children = null, divClass = "" }) {
  divClass += " modal-box relative";
  return (
    <>
      <div className="modal" id={id}>
        <div className={divClass}>
          <a href="#" className="btn btn-sm btn-circle btn-primary absolute right-2 top-2">
            {ICONS.home}
          </a>
          {children}
        </div>
      </div>
    </>
  );
}
