if (typeof String.prototype.trimStart !== "function") {
	String.prototype.trimStart = function () {
		return this.replace(/^\s+/, "");
	};
}
if (typeof String.prototype.trimEnd !== "function") {
	String.prototype.trimEnd = function () {
		return this.replace(/\s+$/, "");
	};
}
if (typeof Array.prototype.map !== "function") {
	Array.prototype.map = function (callback, thisArg) {
		for (var i = 0, n = this.length, a = []; i < n; i++) {
			if (i in this) a[i] = callback.call(thisArg, this[i]);
		}
		return a;
	};
}

function getCookies() {
	var c = document.cookie,
		v = 0,
		cookies = {};
	if (document.cookie.match(/^\s*\$Version=(?:"1"|1);\s*(.*)/)) {
		c = RegExp.$1;
		v = 1;
	}
	if (v === 0) {
		c.split(/[,;]/).map(function (cookie) {
			var parts = cookie.split(/=/, 2),
				name = decodeURIComponent(parts[0].trimLeft()),
				value =
					parts.length > 1
						? decodeURIComponent(parts[1].trimRight())
						: null;
			cookies[name] = value;
		});
	} else {
		c.match(
			/(?:^|\s+)([!#$%&'*+\-.0-9A-Z^`a-z|~]+)=([!#$%&'*+\-.0-9A-Z^`a-z|~]*|"(?:[\x20-\x7E\x80\xFF]|\\[\x00-\x7F])*")(?=\s*[,;]|$)/g
		).map(function ($0, $1) {
			var name = $0,
				value =
					$1.charAt(0) === '"'
						? $1.substr(1, -1).replace(/\\(.)/g, "$1")
						: $1;
			cookies[name] = value;
		});
	}
	return cookies;
}

export default function getCookie(name) {
	return getCookies()[name];
}

function tempLogin(username, password) {
	postUserPassForm("/login/authenticate", username, password);
}

function addUser(username, password) {
  postUserPassForm("/adduser/create", username, password);
}

function postUserPassForm(url, username, password) {
	let formData = new FormData();
	formData.append("username", username);
	formData.append("password", password);

	fetch(url, {
		method: "POST",
		body: formData,
	});
}
