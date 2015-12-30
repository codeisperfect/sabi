execfile(ROOT+"py/help.py");
execfile(ROOT+"py/config.py");
execfile(ROOT+"py/ajax.py");
execfile(ROOT+"py/sql.py");

class mypagehandler(pagehandler):
	def __init__(self, name):
		pagehandler.__init__(self, name, {"isnet": True, "headdata": ""}, {"defaultmsg": ""});

	def index(self):
		return mifu(getcontent(["aboutus"]), {"mohit": "Saini"});

