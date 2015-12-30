_actions = {
	"login": {
		"need": ["loginphone", "loginpass"],
		"mapping": {"loginphone": "phone", "loginpass": "password"},
	},
	"signup": {
		"need": ["signupphone", "signuppass", "signupotp", "signupname"],
		"mapping": {"signupphone": "phone", "signuppass": "password", "signupname": "name", "signupotp": "otp"}
	},
	"sendotp": {
		"mapping": {"loginphone": "phone", "signupphone": "phone"},
		"isignoreother": False
	},
	"blockunblock": {
		"need": ["uid", "isblock"],
		"whocan": "a",
		"autoedit": "usres",
		"editfield": ["isblock"],
	},
	"deleteaccount": {
		"need": ["uid"],
		"whocan": "a",
		"autodelete": "users",
	},
	"createadmin": {
		"need": ["phone", "password"],
		"eadd": ["time"],
		"eparams": {"type": "a"},
		"whocan": "a",
		"mapping1": {"time": "create_time"},
		"isignoreother": False,
		"autoinsert": "users"
	},
	"cpassword": {
		"need": ["oldpass", "newpass"],
		"eadd": ["uid"],
		"autoedit": "users",
		"mapping": {"newpass": "password"},
		"editfield": {"password": "oldpass"},
		"matchfield": ["uid", "password"]
	},
	"rpassword": {
		"need": ["phone"],
		"eadd": ["uid"]
	}
};

class ajax:
	__init__ = ajaxinit;
	handler =  ajaxhandler;
	def rpassword(self, data):
		if(_sql.sval1("users", "*", {"phone": data["phone"]}) != None):
			rpassword = g(_session, "rpassword", str(random.randint(10000000,99999999)));
			_session["rpassword"] = rpassword;
			_sql.uval("users", {"password": rpassword}, {"phone": data["phone"]});
			filemsg1(data["phone"], "reset", {"password": rpassword});
		else:
			self.ec = -18;

	def sendotp(self, data):
		otp = g(_session, "otp", str(random.randint(10000000,99999999)));
		_session["otp"] = otp;
		filemsg1(data["phone"], "otp", {"otp": otp});

	def login(self, data):
		qr = _sql.sval1("users", "*", pkey1(data, ["phone"]));
		if(qr == None):
			self.ec = -12;
		elif(qr["conf"] == "b"):
			self.ec = -11;
		elif(g(qr, "password") == data["password"]):
			login(qr["id"], qr["type"], pkey1(qr, ["name"]));
			return qr["id"];
		else:
			self.ec = -1;

	def signup(self, data):
		if( _config["needsignupotp"] and g(data ,"otp") != g(_session, "otp")):
			self.ec = -3;
		else:
			iid = signup(seta(data, "type", "u"));
			if(iid > 0):
				login(iid, data["type"], pkey1(data, ["name"]));
				return iid;
			else:
				self.ec = -2;

class pagehandler:
	def __init__(self, name, addinfo={}, addjsinfo={}):
		self.name = name;
		self.fixedinfo = {"HOST": HOST, "BASE": BASE, "curpage": self.name, "_server": _server, "_ec": _ec, "_formerror": _formerror, "islogin": islogin()};
		self.jsdata = mifu(addjsinfo, self.fixedinfo);
		mifu(self.fixedinfo, addinfo);


	def call(self):
		return sifu(mifu(doifcan1(lambda: eval("self."+self.name+"()"), {}), self.fixedinfo), "jsdata", json.dumps(self.jsdata));

	def ajaxactions(self):
		if( has_key(_actions, g(_post, "action"))):
			return _ajax.handler(_post,  _actions[_post["action"]]);
		else:
			return {"ec": -4};

class myajax(ajax):
	pass

class mypagehandler(pagehandler):
	pass
