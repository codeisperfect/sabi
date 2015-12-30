define main(acss:["css/materialize.min.css", "mslib/css/lib.css?reload", 'css/gfont.css?reload', 'css/main.css?reload'], ajs:['mslib/js/jquery-2.1.1.min.js','mslib/js/materialize.min.js', 'mslib/js/lib.js?reload','mslib/js/libhelp.js?reload','mslib/js/libhtml.js?reload', 'mslib/js/libfedefault.js?reload', 'mslib/js/main.js?reload'], title: None, css:[], js:[], bodystyle:{}, htmlstyle:{}, headdata: "", websiteicon: None) {
	css = acss + css;
	js = ajs + js;
	print("<!DOCTYPE html>");
	html(style:htmlstyle){
		head(){
			link(attr: {rel:" shortcut icon", type: "image/x-icon", href: websiteicon});
			base(attr:{href:HOST});
			title(){	print(title); }
			print(headdata);
			for(i, css) {
				link(attr:{href:i, rel:"stylesheet", type:"text/css", media: "screen,projection"});
			}
		}
		body(style:bodystyle){
			innerHTML();
			script(attr:{type:"text/javascript"}) {
				print("var jsdata = " + jsdata+";");
				print("var ec  = jsdata['_ec'] ;");
				print("var ve  = jsdata['_formerror'];");
			}
			for(i, js) {
				script(attr:{type:"text/javascript", src:i});
			}
		}
	}
}


define disptabs(tabname: [], tablink: [], liclass: None, active: None) {
	for(i, j, tabname) {
		li(class: liclass) {
			isactive = ((active == tablink[j]) ? "active" : " ");
			a(attr: { href: tablink[j] }, class: isactive ) {
				print(i);
			}
		}
	}
}

define header1(tabname:[], tablink:[]) {
	div(class: "navbar-fixed ") {
		nav(class:"white", attr:{role: "container"}) {
			div(class: "nav-wrapper container") {
				a(attr:{id: "logo-container", href: HOST}, class: "brand-logo") {
					img(attr:{src: "photo/mylogo1.png"}, class: "circle responsive-img", style:{"vertical-align": "middle"});
				}
				ul(class: "right hide-on-med-and-down") {
					disptabs(tabname: tabname, tablink: tablink);
				}
			}
		}
	}
}


define header1_cp(tabname:[], tablink:[]) {
	div(class: "navbar-fixed ") {
		nav(class:"white", attr:{role: "container"}) {
			div(class: "nav-wrapper container") {
				a(attr:{id: "logo-container", href: HOST}, class: "brand-logo") {
					img(attr:{src: "photo/mylogo1.png"}, class: "circle responsive-img", style:{"vertical-align": "middle"});
				}
				ul(class: "right hide-on-med-and-down") {
					disptabs(tabname: tabname, tablink: tablink);
					headertabs_cp();
				}
				ul(id: "nav-mobile", class: "side-nav") {
					headertabs_cp();
				}
				a(attr:{"data-activates": "nav-mobile"}, class: "button-collapse") {
					icon(name: "menu");
				}
			}
		}
	}
}



define icon(aclass: "") {
	i(class: "material-icons "+aclass, style: style){
		print(name);
	}
}

define icon1(class: None) {
	attr["src"] = img;
	img(attr: attr, style:{"margin-bottom": "-5px"}, class: class);
}


define checkbox1(checked: None, label:"Check", aclass:"", labels:{}) {
	span() {
		input(attr:{type: "checkbox", id: id, checked: checked}, class: "filled-in "+aclass, data: data);
		label(attr:{"for": id}, style: labels) {
			print(label);
		}
	}
}


define checkbox2(checked: None, label:"Check", aclass:"", labels:{}) {
	span() {
		input(attr:{type: "radio", id: id, checked: checked}, class: "with-gap "+aclass, data: data);
		label(attr:{"for": id}, style: labels) {
			print(label);
		}
	}
}

define bigf(font: "65px") {
	span(style:{"font-size": font, "text-shadow": "3px 3px 3px #000, 2px 2px 2px blue"}, color: color) {
		print(name);
	}
}

define bigf1(font: "40px") {
	bigf(color: color,font: font, name: name);
}


define height() {
	div(style:{height: val+"px"});
}

define resimg(aclass:"", opacity: None) {
	style["opacity"] = opacity;
	img(class: "responsive-img "+aclass, attr:{src: src}, style:style);
}

define circleimg(opacity: None) {
	resimg(aclass:"circle", src:src, opacity:opacity);
}

define divpedding(text:"", padding:"5px") {
	div(style:{padding: padding}, class: class){
		print(text);
		innerHTML();
	}
}

define textdiv(text:"", fontw: None, font: None, color: None, class: None, id: None, style:{}) {
	style["font-size"] = font;
	style["font-weight"] = fontw;
	div(style: style, color:color, class: class, id: id){
		innerHTML();
		print(text);
	}
}

define textdiv1(font: "20px", fontw: None, color: None, class: None, text: "") {
	textdiv(font: font, fontw: fontw, color: color, class: class, text: text, style: style) {
		innerHTML();
	}
}

define textdiv2(font: "25px", fontw: "900", color: None, class: None, text: "", style:{"padding": "11px"}) {
	textdiv(font: font, fontw: fontw, color: color, class: class, text: text, style: style) {
		innerHTML();
	}
}


define a1(class: None, text:"", href: None) {
	a(attr: attr, style: style, class: class) {
		print(text);
		innerHTML();
	}
}

define starrating(val: 5) {
	for(i, val) {
		img(attr:{src: "photo/rating4.png"}, style:{"margin": "-1px", width: "22px"});
	}
}

define input1(aclass: "col s6",  type: "text", dc: "simple", icon: None, dname: None, value: None, iclass: None, disabled: None) {
	div(class: "input-field "+aclass) {
		if(icon) {
			icon(name: icon, aclass: "prefix");
		}
		data["name"] = label;
		data["dc"] = dc;
		if(dname != None) {
			data["name"] = dname;
		}
		input(attr:{id: id, type:type, value: value, disabled: disabled}, class: iclass, data: data);
		label(attr:{"for": id}) {
			print(label);
		}
	}
}



define input2(aclass: "col s6",  type: "text", iclass: None, label: None, placeholder: None, value: None) {
	div(class: "input-field "+aclass) {
		input(attr:{id: id, type:type, name:id, placeholder: placeholder, value: value}, class: iclass);
		label(attr:{"for": id}) {
			print(label);
		}
	}
}

define input3(aclass: "col s6",  type: "text", dc: "simple", icon: None, dname: None, value: None, iclass: "", name: None, id: None) {
	div(class: "input-field "+aclass) {
		if(icon) {
			icon(name: icon, aclass: "prefix");
		}
		data["name"] = label;
		data["dc"] = dc;
		if(dname != None) {
			data["name"] = dname;
		}
		input(attr:{type:type, value: value, placeholder: label, name: name, id: id}, class: "inputph "+iclass, data: data);
	}
}

define textarea1(aclass: "col l12 m12 s12") {
	div(class: "input-field "+aclass) {
		textarea(attr:{id: id, name:id}, class: "materialize-textarea");
		label(attr:{"for": id}) {
			print(label);
		}
	}
}

define button1(aclass: "" ) {
	button(class: "btn waves-effect waves-light btn "+aclass, data: data, attr: attr, datas: datas) {
		print(name);
	}
}

define button2(aclass: "", text: "Submit") {
	button(class: "btn waves-effect waves-light btn "+aclass, data: data, attr: attr, datas: datas) {
		print(text);
	}
}

define hidinp(name: None, value: None) {
	input(attr: {type: "hidden", name: name, value: value});
}


define popupmodal(title: "Popup Title", body: "") {
	div(attr:{id: id}, class: "modal") {
		div(class: "modal-content container-fluid") {
			div(class: "row") {
				div(class: "col l12 m12 s12 realtexttitle", style: {"font-size": "20px"}) {
					print(title);
				}
			}
			div(class: "row") {
				div(class: "col l12 m12 s12 realtext") {
					print(body);
					innerHTML();
				}
			}
		}
	}
}

define popupmodal_confirm(title: "Title", body: "") {
	div(attr:{id: id}, class: "modal") {
		div(class: "modal-content container-fluid") {
			div(class: "row") {
				div(class: "col l12 m12 s12 realtexttitle", style: {"font-size": "20px"}) {
					print(title);
				}
			}
			div(class: "row") {
				div(class: "col l12 m12 s12 realtext") {
					print(body);
					innerHTML();
				}
			}
		}
		div(class: "modal-footer") {
			button2(aclass: "realyes modal-action modal-close", text: "Agree");
		}
	}
}

define table1(rows:[], thead:[], class: None) {
	table(class: class) {
		thead() {
			for(i, thead) {
				th() {
					print(i);
				}
			}
		}
		tbody() {
			for(i, ii, rows) {
				tr() {
					for(j, jj, i) {
						td() {
							print(j);
						}
					}
				}
			}
		}
	}
}



define errorbox() {
	div(class: "row hiddenerror") {
		div(class: "col s12 l12") {
			div(class: "card-panel red white-text center errortext") {
				print("");
			}
		}
	}
}


define switch1(on: "Yes", off: "No") {
	div(class: "switch") {
		label() {
			print(off);
			input(attr:{type: "checkbox", name: name});
			span(class: "lever");
			print(on);
		}
	}
}


define switch2(class: "col l3 s12 m6") {
	div(class: class) {
		div(class: "m5") {
			print(label);
			switch1(name: name);
		}
	}
}


define select2(tlist:[], dclass: "col l3 s12 m6", class: "browser-default", selected: None, toptext: None, vlist: None, name: None, style: {}) {
	div(class: dclass) {
		select1(class: class, tlist: tlist, vlist: vlist, toptext: toptext, selected: selected, name: name, style:style);
	}
}

define mselect(tlist:[], vlist: None, selected: None) {
	for(i, ii, tlist) {
		attrs = {};
		if (vlist != None) {
			attrs["value"] = vlist[ii];
		} else {
			attrs["value"] = (ii+1);
		}
		if( selected == ii ) {
			attrs["selected"] = "";
		}
		checkbox1(label: i, id: id+"_"+ii);
	}
}


define mselect1(tlist:[], vlist: None) {
	div(id: id, class: "dropdown-content p5", tlist:[]) {
		mselect(vlist:vlist, tlist: tlist, id: id);
	}
	a(class: "dropdown-button", data:{activates: id}) {
		print(label);
	}
}

define mselect2(class: "col l3 s12 m6") {
	div(class: class) {
		div(class: "mselect complexinput", data:{complexinput: "ci_checkbox"}, attr: {name: id}) {
			mselect1(id: id, tlist: tlist, label: label, selectall: selectall);
		}
	}
}


define select1(tlist:[], class: "browser-default", aclass: "", selected: None, name: None, vlist: None, toptext: None, style: {}) {//class, tlist, vlist, toptext, selected
	select(class: class+" "+aclass, attr:attr, style: style) {
		if(toptext != None) {
			option(attr:{value: ""}) {
				print(toptext);
			}
		}
		for(i, ii, tlist) {
			attrs = {};
			if (vlist != None) {
				attrs["value"] = vlist[ii];
			} else {
				attrs["value"] = (ii+1);
			}
			if(selected == attrs["value"]) {
				attrs["selected"] = "";
			}
			option(attr:attrs) {
				print(i);
			}
		}
	}
}

