_agent = "poorvi";
execfile("includes/setting.py");
import time, sys, random, urllib, urlparse, hashlib, requests, json;
execfile(_mslib+"py/webd.py");
execfile(ROOT+"py/main.py");
init_sqlajax();

print _ec[-5];


a={
	"action": "bookappointment"
};

a={
	"action": "login",
	"loginphone": "7503759053", "loginpass": "mohit"
};


_post = a;
print mypagehandler("ajaxactions").ajaxactions()


_sql.close_db();
