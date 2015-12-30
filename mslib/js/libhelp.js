
function latlandist(lat1, lng1, lat2, lng2) {
	var degtorad = function(x){
		return x*(Math.PI/180);
	}
	var R = 6371000; // metres
	var R = 7270000; // metres
	var ph1 = degtorad(lat1);
	var ph2 = degtorad(lat2);
	var dph = degtorad(lat2 - lat1);
	var dlem = degtorad(lng2 - lng1);
	var sin = Math.sin;
	var a = sin(dph/2) * sin(dph/2) + sin(ph1)*sin(ph2)*sin(dlem/2)*sin(dlem/2);
	var c = 2*Math.atan2(Math.sqrt(a), Math.sqrt(1-a));
	return R*c;
}


function cluster_points(plist, f) { //f (p0, p1) -> is p0 friend of p1
	var clusters = [];
	var limit = 100;
	while(plist.length > 0) {
		limit--;
		cluster = filter(function(x) {
			return f(x,plist[0]);
		}, plist);
		plist = listaminusb(plist, cluster);
		clusters.push(cluster);
	}
	return clusters;

}

function geolocgroup(plist, zoom, screen_distance) {
	var scale = 1183315100;//scale on google map when zoom = 0
	return cluster_points(plist, function(x,y) {
		var distance = latlandist(x[0], x[1], y[0], y[1]);//meter
		return (distance*Math.pow(2, zoom) <= screen_distance*scale);
	});
}

function geolocgroup1(plist, zoom, screen_distance) {
	var groupslist = geolocgroup(plist, zoom, screen_distance);// Assert( Every cluster has alteast 1 point in it)
	return map(function(x) {
		var cluster_llsum = fold(function(y,z) {
			return [y[0]+z[0], y[1]+z[1]];
		} ,x, [0,0]);
		var lenc = x.length;//number of point in that cluster
		return [cluster_llsum[0]/lenc, cluster_llsum[1]/lenc, x[0][2], map(function(y){ 
			return y[2]; 
		}, x)];
	} ,groupslist);

}



function indexedlist(l) {
	return map(function(x,y) {
		return (l.length > 1 ? ((int(y)+1)+". "+x):x);
	}, l);
}

function setallattr(obj, attrs) {
	mapp(function(x,y) {
		$(obj).attr(y, x);
	}, attrs);
}


function time() {
	return floor(new Date().getTime()/1000);
}

function timem() {
	return floor(new Date().getTime());
}



var validation={
	isnull: function (st){
		for(var i=0;i<st.length;i++){
			if(!(st[i]==' ' || st[i]=='\n' || st[i]=='\t'))
				return false;
		}
		return true;
	}
};


var HOST = jsdata["HOST"];

////////////////////////////////// Don't use the functions, defined beyond this point.


//////// To Modify Functions

function map(f, l, filt, keyf) { //To modify it. Make it python map
	return values(mapp(f, l, filt, keyf));
}


/////These Are To Delete Functions


var funcs={
	error: [{timeout: 4000}, function() {
		Materialize.toast(msg, timeout, 'rounded');
	}]
};


function parsejson(d) {
	try{
		return JSON.parse(d);
	} catch(e){
		return null;
	}
}



function spacesplit(st) { // To delete
	return map(id, st.split(" "), function(x){ return x!="" });
}

function push1(l1, x) { 
	return r1(l1.push(x), l1);
}

function inlist(l, e) {
	return (l.indexOf(e)!=-1);
}

function push2(l, x) {
	return inlist(l,x) ? l: push1(l, x);
}

function merge_f(l1, l2, push_style) {
	return fold(function(x,y) { return push_style(x,y); }, l2, l1);
}

function merge1(l1, l2) { // To be deleted
	return merge_f(l1, l2, push1);
}

function merge2(l1, l2) { // To be deleted
	return merge_f(l1, l2, push2);
}

function runf(fname, args) { //Assume list of funcs is defined.
	if(haskey(funcs, fname)) {
		if(typeof(funcs[fname]) === "function") {
			var defargs = {};
			var func = funcs[fname];
		} else {
			var defargs = funcs[fname][0];
			var func = funcs[fname][1];
		}
		mergeifunset( args, defargs );
		for(var i in args) {
			eval("var "+i+" = args[i];");
		}
		eval("var "+fname+" = "+func.toString());
		return eval(fname+"();");
	}
}

function runo(fname, obj) {
	return runf(fname, dattr(obj));
}

function runo1(fname, obj) {
	return runf(fname, sifu(dattr(obj), "obj", obj));
}


function mapo(f, objs, filt) {
	var modf = function(f){ return (f==null ? null:function(x){ return f(objs[x], x); }); };
	return map(modf(f), range(objs.length), modf(filt));
}

function id(x) {
	return x;
}

function hasgoodchar(inp) {
	var uselesschar=" \t\n";
	for(var i=0;i<inp.length;i++){
		if(uselesschar.indexOf(inp[i])==-1)
			return true;
	}
	return false;
}

var success={
	id:0,
	opentime:{},
	hideafter:3000,//milli seconds
	push:function(msg,convert){
		var sid=success.id;
		success.opentime[sid]=time("m");
		if(convert==null){
			msg=smilymsg(msg);
		}
		else if(convert==false){

		}
		var addnew='<div id="alert_'+sid+'" class="success-msg" style="display:none;" ><span onclick="success.closeme($(this).parent());" class="closePopup closeSuccess" >&times;</span>'+msg+'</div>';
		$("#success_alerts").append(addnew);
		alobj=$("#alert_"+sid);
		alobj.fadeIn(function(){
			setTimeout(function(){
				success.cleaner();
			},success.hideafter);
		});
		success.id++;
	},
	closeme:function(alobj){
		alobj.fadeOut(function(){
			alobj.remove();
		});
	},
	cleaner:function(){
		var ot=success.opentime;
		var zombies=[];
		for(var i in ot){
			if(time("m")-ot[i]>success.hideafter){
				success.closeme($("#alert_"+i));
				zombies.push(i);
			}
		}
		for(var i in zombies){
			if($("#alert_"+i).length<1){
				delete success.opentime[i];
			}
		}
	}
};
