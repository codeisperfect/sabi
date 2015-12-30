function selectAll(obj) {
	var getchecboxs = function (cur) {
		return merge1(tolist(cur.find("input[type=checkbox]")), tolist(cur.find("input[type=radio]")));
	}
	var cur = lookontop(obj, function(x){
		return (getchecboxs(x).length > 1);
	});
	var cblist = getchecboxs($(cur));
	for(var i=1; i< cblist.length; i++ ) {
		cblist[i].checked = obj.checked;
	}
}

function lookontop_elm(obj, elm) {
	return lookontop(obj, function (x){
		return (x.prop("tagName") == elm);
	});
}

function lookontop_selector(obj, s) {
	return lookontop(obj, function (x){
		return ($(s).is(x));
	});
}

function lookontop_form(obj) {
	return lookontop_elm(obj, "FORM");
}


function lookontop(obj, conditionf) {
	var cur;
	for(cur = $(obj); cur.length > 0 && !conditionf(cur); cur = cur.parent());
	return (cur.length > 0 ? cur[0]: null);
}

function errora(msg) {
	runf("error", {msg: msg, timeout: 5000});	
}





function attr(obj) {
	var alla=obj.attributes;
	var attrso={};
	for(var i=0;i<alla.length;i++)
		attrso[alla[i].name]=alla[i].value;
	return attrso;
}

function htmlspecialchars(str) {
	return str.replaceall({"&":"&amp;", '"':"&quot;", "'":"&#039;", "<":"&lt;", ">":"&gt;"});
}

function smilymsg(inp){
	inp=htmlspecialchars(inp);
	inp=inp.replaceall({"\n":"<br>","\t":"&nbsp;&nbsp;&nbsp;","  ":"&nbsp;&nbsp;"});
	return inp;
}

function dattr(obj) {
	return mapp(id, attr(obj), function(x, y) { return (y.substr(0, 5) == "data-"); }, function(x){ return x.substr(5); });
}


function dsattr(obj) {
	return mapp(id, dattr(obj), function(y, x){ return x.substr(0,4)=="send"; }, function(x){ return x.substr(4); });
}

function hvali(x) {
	return hval("#"+x);
}



function isNum(n){
	return (isFinite(n) && n!="");
}

var checkValidInput={
	'idel':function (obj){
		return true;
	},
	'simple':function (obj){
		return obj.value!="";
	},
	'email':function (obj){
		return (obj.value.match("^[a-zA-Z0-9\._%+-]+@[a-zA-Z0-9\.-]+[\.][a-zA-Z]{2,4}$")!=null);
	},
	'password':function (obj){
		return (obj.value!="" && obj.value == $("#password").val()  );
	},
	password1: function(obj) {
		return isregexmatch(obj.value, "^.+$");
	},
	'phone':function (obj){
		var pn=obj.value;
		return (isFinite(pn) && pn.length==10 && pn[0]!='+' && pn[0]!='-');
	},
	'otp':function (obj){
		var pn=obj.value;
		return (isFinite(pn) && pn.length==8 && pn[0]!='+' && pn[0]!='-');
	},
	'pnumber':function (obj){
		return isNum(obj.value) ;
	},
	'int':function(obj){
		return isNum(obj.value);
	},
	'pint':function(obj){
		return (checkValidInput.int(obj) && obj.value[0]!='-');//remember obj.value.length is >=1 in second term.
	},
	checkcheckbox:function(obj){
		return obj.checked;
	},
	msg:function(obj){
		return hasgoodchar(obj.value);
	},
	'isChecked':function (obj){
		return (obj.getAttribute('data-condition')==null || this[ obj.getAttribute('data-condition') ](obj)) ;
	}
};

function getFormInputs(obj,add){
	var inputs=['INPUT','TEXTAREA','SELECT'];
	outp={};
	for(i=0;i<inputs.length;i++){
		var ilist=$(obj).find(inputs[i]);
		for(j=0;j<ilist.length;j++){
			if(ilist[j].getAttribute('name')!=null){
				var fn=ilist[j].getAttribute('name');
				var fv=(ilist[j].value);
				if(ilist[j].type=="checkbox")
					fv=ilist[j].checked;
				outp[fn]=fv;
			}
		}
	}
	outp[add]="";
	return outp;
}

function hval(x) {
	return $(x).html().trim();
}

function uploadfile(obj, name) {
	var formjobj=$(obj).parent();
	if(!(formjobj.find("input[name="+name+"]").length>0)){
		var elm=document.createElement("input");
		elm.setAttribute("type","file");
		elm.setAttribute("name",name);
		elm.setAttribute("style","display:none;");
		elm.onchange=function (){
			formjobj.submit();
		}
		formjobj[0].appendChild(elm);
	}
	else{
		var elm=formjobj.find("input[name="+name+"]")[0];
	}
	elm.click();
}

function hs_toggle(ids, timetaken) {
	doforall(ids, function(e){
		$("#"+e).slideToggle(timetaken);
	});
}



function hideshowdown(h,s){
	$("#"+h).slideUp();
	$("#"+s).slideDown();
}




function forminps(obj) {
	var getval = function (x) {
		if (x.type == "checkbox")
			return 0+x.checked;
		else if ($(x).hasClass("complexinput"))
			return runo1(dattr(x).complexinput, x);
		else
			return $(x).val();
	};
	var allinps = fold(function(x,y){
					return $.merge(x, mapo(function(x){
						return sifu(pkey(attr(x), ["id", "name"]), "val", getval(x)); 
					}, $(obj).find(y)));
				},["input", "textarea", "select", ".complexinput"], []);
	return fold(function(x, y){
			if(haskey(y, "name")){
				x[y.name] = y.val;
			} else if(haskey(y, "id")){
				x[y.id] = y.val;
			}
			return x;
		}, allinps, {});
}


function forminps1(obj) {
	var getval = function (x) {
		if (x.type == "checkbox")
			return 0+x.checked;
		else if ($(x).hasClass("complexinput"))
			return runo1(dattr(x).complexinput, x);
		else
			return $(x).val();
	};
	var allinps = fold(function(x,y){
					return $.merge(x, mapo(function(x){
						return mifu(pkey(attr(x), ["id", "name", "data-dc", "data-name"]), {val: getval(x), obj: x}); 
					}, $(obj).find(y)));
				},["input", "textarea", "select", ".complexinput"], []);
	return fold(function(x, y){
			var feildname = null;
			if(haskey(y, "name")){
				feildname = y.name;
			} else if(haskey(y, "id")){
				feildname = y.id;
			}
			if(feildname != null) {
				x['val'][feildname] = y.val;
				if(haskey(y, "data-dc")) {
					if(!checkValidInput[y["data-dc"]](y.obj)) {
						var errorname = g(y, "data-name", feildname);
						x['error'].push(errorname+": "+g(ve, y["data-dc"], ""));
					}
				}
			}
			return x;
		}, allinps, {'val':{}, 'error': []});
}




var finp = forminps;



var ms = {
	reload: function(inp) {
		window.location.href = (typeof(inp) == "undefined" ? window.location.href: (jsdata.BASE+inp));
	}
};

funcs.ci_checkbox = function() {
	return mapo(function(x,y){
		return y+1;
	}, $(obj).find("input[type=checkbox]"), function (x,y) {
		return x.checked;
	}).join("-");
}

function get_hidden_inp(name, val) {
	var elm = document.createElement("input");
	elm.type = "hidden";
	elm.value = val;
	elm.name = name;
	return elm;
}

function add_hidden_inps(fobj, inps) {
	mapp(function(x,y){
		var selector = $(fobj).find("input[type=hidden][name="+y+"]");
		if (selector.length == 0) {
			$(fobj).prepend($(get_hidden_inp(y, x)));
		} else {
			selector.val(x);
		}
	}, inps);
}


function msg(x) {
	return runf("error", {msg: x});
}


//////////////////////// To Delete ///////////////////////


funcs["req"]= [{callback: id}, function () {//params, callback
	$.post(HOST+"index.php/ajaxactions", params, function(d, s) { if(s === 'success') {
		callback(d);
	}});
}];

funcs["req1"] = [{callback: id, callanyway: id, errorh: errora}, function() { //params
	return runf("req", {callback: function(d) {
		var x = parsejson(d);
		if( x === null )
			errorh("Unexpected Error"+"\n"+d);
		else {
			if(x.ec < 0)
				errorh(ec[x.ec]);
			else
				callback(x);
		}
		callanyway(d);
	}, params: params});
}];

funcs["sreq"] = [{waittext: " ... ", restext: null, bobj: null, form: null, params: null, fobj: null, res:null, callanyway: id, errorh: null, ferror: null}, function() {// obj, action
	fobj = (fobj == null ? obj: (fobj == "" ? lookontop_form(obj): eval(fobj)));
	bobj = (bobj == null ? obj: (bobj == "" ? ($(obj).find("button[type=submit]")[0]):eval(bobj)));
	var errorhf = (errorh == null ? errora: function(x) {
		runf(errorh, mifu(dattr(obj), {obj:obj, msg: x}));
	});
	params = ( params ==null ? {}: eval(params) );
	var forminps_data = forminps1(fobj);
	if(ferror == null && forminps_data["error"].length > 0) {
		errorhf(indexedlist(forminps_data.error).join("<br>"));
	} else {
		errorhf("");
		params = mifu(params, sifu(forminps_data["val"], "action", action));
		params = mifu(params, dsattr(obj));
		var prvhtml = bobj.innerHTML;
		bobj.disabled = true;
		if(waittext != "" ) {
			bobj.innerHTML = waittext;
		}
		var bobj_innerHTML = prvhtml;
		runf("req1", { "params": params, callback: function(data) {
			bobj_innerHTML = (restext == null ? prvhtml: restext);
			if( res!=null ) {
				eval(res);
			}
		}, callanyway: function	(x) {
			if(restext != "") {
				bobj.innerHTML = bobj_innerHTML;
			}
			bobj.disabled = false;
			callanyway(x);
		}, errorh: errorhf});
	}
	return false;
}];

funcs["formsreq"] = [{fobj: null}, function() {//action
	fobj = (fobj == null ? obj: eval(fobj));
	runf("req1", {params: sifu(forminps(fobj), "action", action)});
	return false;
}];



funcs["sreq_confirm"] = [{confirm: "Are you sure ?"}, function(){
	ms.confirm("Confirmation", confirm, function(){
		runf("sreq", mifu(dattr(obj), {obj: obj}));
	});
}];

mergeforce(funcs, {
	error_login: function() {//obj, msg
		var errore = $(lookontop_form(obj)).find(".hiddenerror");
		if(msg.length > 0)
			errore.fadeIn(1000);
		else
			errore.hide();
		errore.find(".errortext").html(msg);
	},
});


ms.popup = function(title, body) {
	var popup = $("#popupmodal");
	popup.find(".realtexttitle").html(title);
	popup.find(".realtext").html(body);
	popup.openModal();
}


ms.confirm = function(title, body, callifyes) {
	var confirm = $("#popupmodal_confirm");
	confirm.find(".realtexttitle").html(title);
	confirm.find(".realtext").html(body);
	var acceptbutton = confirm.find(".realyes")[0];
	acceptbutton.disabled = false;
	acceptbutton.onclick = function() {
		callifyes();
		acceptbutton.disabled = true;
	}
	confirm.openModal();
}
