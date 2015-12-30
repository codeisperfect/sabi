mifa(_ec, {
});

mifa(_actions, {
	"bookappointment": {
		"need": ["datetimetext"],
		"whocan": "login"
	}
});

class myajax(ajax):
	def bookappointment():
		return "Mohit";
