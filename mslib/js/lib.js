var floor = Math.floor;
var int = parseInt;
var ceil = Math.ceil;
var _definpname = "_definp";

function fold(f, l, def) {
	for(i in l ) {
		def = f(def, l[i], i);
	}
	return def;
}

function idf(x) {
	return x;
}

var keys = function(arr) {
	map(function(y,x) {
		return x;
	}, arr);
};


function tolist(l) {
	return map(function(x){
		return l[x];
	}, range(l.length));
}

function values(a) { // just like python dict.values
	var outp = [];
	for(i in a) {
		outp.push(a[i]);
	}
	return outp;
}

function mapp(f, l, filt, keyf) {
	if(keyf == null) 
		keyf = idf;
	var outp = {};
	for(var i in l) {
		if(filt == null || filt(l[i], i) )
			outp[keyf(i, l[i])] = f(l[i], i);
	}
	return outp;
}

function mappl(f, l, filt, keyf) {
	return values(mapp(f, l, filt, keyf));
}

function filter(f, l) {
	return map(id, l, f, idf);
}

function range3(a, b, c) {
	var outp = [];
	for(var i=a; i<b; i+=c) {
		outp.push(i);
	}
	return outp;
}

function range2(a, b) {
	return range3(a, b, 1);
}

function range(a) {
	return range2(0, a);
}


function rifn(x, y) {
	return (x == null ? y:x);
}

function fi(definp) {
	return mappl(function(y,x){
		return "var "+x+" = rifn("+x+","+_definpname+"."+x+")";
	}, definp).join(";");
}

function setifunset(data,key,val, isforce) {
	var _definp = {isforce: false};
	eval(fi(_definp));
	if(!haskey(data, key) || isforce )
		data[key] = val;
	return data;
}

var sifu = setifunset;

function mergeifunset(dict1,dict2){
	for(i in dict2){
		setifunset(dict1,i,dict2[i]);
	}
	return dict1;
}

var mifu = mergeifunset;

function setforce(data, key, val) {
	data[key] = val;
	return data;
}

function mergeforce(d1, d2) {
	return fold(function(x, y, k){ return setforce(x, k, y) }, d2, d1);
}


function haskey(arr, key){
	return (key in arr);
}

function pkey(arr, keys) {
	return mapp( function(x){ return arr[x]; }, keys, function(x){return haskey(arr, x); }, function(x){return keys[x];});
}

function belongs(l, a) {
	return (l.indexOf(a) != -1);
}

function append(l, a) {
	return r1(l.push(a), l);
}

function appenduniq(l, a) {
	if(!belongs(l, a))
		l.push(a);
	return l;
}

function addluniq(l1, l2) {
	return fold(function(y, x){ return  appenduniq(y, x); }, l2, l1);
}

function listaminusb(l1, l2) {
	return fold(function(x,y){ return belongs(l2, y)?x:appenduniq(x, y); }, l1, []);
}

function nth(l, e) {
	return (e>=0) ? l[e]: l[l.length+e];
}

function r1() { //Assuming atleast one argument is passed
	return nth(arguments, -1);
}

function doifcan(f, args, defaultval) {
	try {
		return f.apply(f, args);
	}
	catch(e) {
		return defaultval;
	}
}

function isdef(x) {
	return (typeof(x) != "undefined");
}

function rifu(x, y) {
	return (isdef(x) ? x:y);
}

function g(l, i, defaultval) {
	return rifu(l[i], 
			isdef(l.length) ? rifu(l[i+l.length], defaultval): defaultval);
}

function isregexmatch(s, regex) {
	return (s.match(regex)!=null);
}


////////////// These method names should be synk with python //////////////////////

