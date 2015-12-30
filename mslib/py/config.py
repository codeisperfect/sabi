(_session, _get, _post, _urlpath, _file, _addinfo) = ({}, {}, {}, '', {}, {});

_urlpath = '';

_config = {};
_config["sql"] = {};
_printout = ""
_toresize = {};
_tosendmail = [];
_phpheader = "";
_config["isrealmsg"] = False;
_config["isrealmail"] = False;
_config["realmail"] = "mailreal";
_config["needsignupotp"] = True;


_config["alltags"] = ["a", "abbr", "acronym", "address", "applet", "area", "article", "aside", "audio", "b", "base", "basefont", "bdi", "bdo", "big", "blockquote", "body", "br", "button", "canvas", "caption", "center", "cite", "code", "col", "colgroup", "datalist", "dd", "del", "details", "dfn", "dialog", "dir", "div", "dl", "!DOCTYPE", "dt", "em", "embed", "fieldset", "figcaption", "figure", "font", "footer", "form", "frame", "frameset", "h1", "h2", "h3", "h4", "h5", "h6", "head", "header", "hr", "html", "i", "iframe", "img", "input", "ins", "kbd", "keygen", "label", "legend", "li", "link", "map", "mark", "menu", "menuitem", "meta", "meter", "nav", "noframes", "noscript", "object", "ol", "optgroup", "option", "output", "p", "param", "pre", "progress", "q", "rp", "rt", "ruby", "s", "samp", "script", "section", "select", "small", "source", "span", "strike", "strong", "style", "sub", "summary", "sup", "table", "tbody", "td", "textarea", "tfoot", "th", "thead", "time", "title", "tr", "track", "tt", "u", "ul", "var", "video", "wbr"];#+["main"];

_onewaytags = ["input", "link", "img", "base", "hr", "br"];

_formerror = {
	"idel": "",
	"simple": "Should not Empty",
	"email": "Not valid email format",
	"password": "Didn't matched",
	"phone": "Should be 10 digit",
	"otp": "Should be 8 digit",
	"password1": "Should Be Strong"
};


_ec = {
	-1: "Incorrect password",
	-2: "Your Phone number is already registered with us",
	-3: "OTP is Incorrect",
	-4: "Action handler not valid",
	-5: "Insufficient arguments",
	-6: "Invalid Input",
	-7: "Incorrect password",
	-8: "This Phone number is already used",
	-9: "Sorry!! You don't have privileges to perform this action",
	-10: "It is already added",
	-11: "Sorry!!You are Blocked!",
	-12: "Invalid phone number",
	-13: "Sorry!! You need to login first",
	-17: "Your old password is Incorrect",
	-18: "Your phone is not registered with us",
};

_sql = None;
_ajax = None;
