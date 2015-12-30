mergeforce(funcs, {
});

ms.showtextarea = function(obj) {
	$(obj).parent().find("div.edittext").slideDown();
}

ms.shownext = function(obj) {
	$(obj).next().slideDown();
}


ms.form = function(obj) {
	return lookontop_form(obj);
}


ms.exportp = function(data) {
	ms.popup("Export", "Redirect Me <a href='"+HOST+data.data+"' >there</a>");
}

if(jsdata.defaultmsg != "") {
	ms.popup("", jsdata.defaultmsg);
}





// function f() {
// 	return $("body").width();
// }

