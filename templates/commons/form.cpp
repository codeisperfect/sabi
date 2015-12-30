define main2(css:[], js:[], bodystyle:{}, htmlstyle:{}, title: "SaveAbhi | Awesome App") {
	js = ["js/main.js?reload"] + js + (isnet ? []:[]);
	main(title: title, css: css, js:js, bodystyle:bodystyle, htmlstyle: htmlstyle, headdata: headdata) {
		innerHTML();
		loginmodal();
		popupmodal(id: "popupmodal");
		popupmodal_confirm(id: "popupmodal_confirm");
	}
}


define header2(tabname:[], tablink:[], tabname1:[], tablink1: []) {
	div(class: "navbar-fixed ") {
		nav(class:"white", attr:{role: "container"}) {
			div(class: "nav-wrapper container") {
				a(attr:{id: "logo-container", href: HOST}, class: "brand-logo center") {
					img(attr:{src: "photo/logo4.png"}, class: "responsive-img", style:{"vertical-align": "middle"});
				}
				ul(class: "left hide-on-med-and-down" ) {
					disptabs(tabname: tabname1, tablink: tablink1);
				}
				ul(class: "right hide-on-med-and-down" ) {
					disptabs(tabname: tabname, tablink: tablink);
					li() {
						a1(href:"#loginmodal", class: "modal-trigger", text: "Login");
					}
				}
				ul(attr:{id: "nav-mobile"}, "class": "side-nav") {
					disptabs(tabname: tabname1, tablink: tablink1);
					disptabs(tabname: tabname, tablink: tablink);
					li() {
						a1(href:"#loginmodal", class: "modal-trigger", text: "Login");
					}
				}
				a(attr:{"data-activates": "nav-mobile"}, "class": "button-collapse") {
					icon(name: "menu");
				}
			}
		}
	}
}


define header2_user(tabname:[], tablink:[], tabname1:[], tablink1:[]) {
	div(class: "navbar-fixed ") {

		ul(id: "dropdown1", class: "dropdown-content") {
			li() {
				a1(href: BASE+"account", text: "Account");
			}
			li() {
				a1(href: BASE+"orders", text: "Orders");
			}
			li() {
				a1(href: HOST+"?logout", text: "Logout");
			}
		}

		nav(class:"white", attr:{role: "container"}) {
			div(class: "nav-wrapper container") {
				a(attr:{id: "logo-container", href: HOST}, class: "brand-logo center") {
					img(attr:{src: "photo/logo4.png"}, class: "responsive-img", style:{"vertical-align": "middle"});
				}
				ul(class: "left hide-on-med-and-down" ) {
					disptabs(tabname: tabname1, tablink: tablink1);
				}
				ul(class: "right hide-on-med-and-down" ) {
					//disptabs(tabname: tabname, tablink: tablink);
					li() {
						a1(href: BASE+"cart") {
							print("Cart");
							span(class: "cartitem badge cartnum", style: {display: "none"}) {
								print("0");
							}
						}
					}
					li() {
						a1(class: "dropdown-button", text: "&nbsp;"*5+loginname+"&nbsp;"*10, data:{activates:"dropdown1"});
						//icon(name: "arrow_drop_down", aclass: "right");
					}
				}
				ul(attr:{id: "nav-mobile"}, "class": "side-nav") {
					disptabs(tabname: tabname1, tablink: tablink1);
					disptabs(tabname: tabname, tablink: tablink);
					li() {
						a1(href: BASE+"account", text: "Account");
					}
					li() {
						a1(href: BASE+"orders", text: "Orders");
					}
					li() {
						a1(href: HOST+"?logout", text: "Logout");
					}
				}
				a(attr:{"data-activates": "nav-mobile"}, "class": "button-collapse") {
					icon(name: "menu");
				}
			}
		}
	}
}

define header2_chef(tabname:[], tablink:[], tabname1:[], tablink1:[]) {
	div(class: "navbar-fixed ") {
		ul(id: "dropdown1", class: "dropdown-content") {
			li() {
				a1(href: BASE+"account", text: "Account");
			}
			li() {
				a1(href: BASE+"orders", text: "Orders");
			}
			li() {
				a1(href: BASE+"chefdeal", text: "Chef Contract");
			}
			li() {
				a1(href: HOST+"?logout", text: "Logout");
			}
		}

		nav(class:"white", attr:{role: "container"}) {
			div(class: "nav-wrapper container") {
				a(attr:{id: "logo-container", href: HOST}, class: "brand-logo center") {
					img(attr:{src: "photo/logo4.png"}, class: "responsive-img", style:{"vertical-align": "middle"});
				}
				ul(class: "left hide-on-med-and-down" ) {
					disptabs(tabname: tabname1, tablink: tablink1);
				}
				ul(class: "right hide-on-med-and-down" ) {
					disptabs(tabname: tabname, tablink: tablink);
					li() {
						a1(class: "dropdown-button", text: "&nbsp;"*5+"Account"+"&nbsp;"*10, data:{activates:"dropdown1"});
						//icon(name: "arrow_drop_down", aclass: "right");
					}
				}
				ul(attr:{id: "nav-mobile"}, "class": "side-nav") {
					disptabs(tabname: tabname1, tablink: tablink1);
					disptabs(tabname: tabname, tablink: tablink);
					li() {
						a1(href: BASE+"account", text: "Account");
					}
					li() {
						a1(href: BASE+"orders", text: "Orders");
					}
					li() {
						a1(href: BASE+"chefdeal", text: "Chef Contract");
					}
					li() {
						a1(href: HOST+"?logout", text: "Logout");
					}
				}
				a(attr:{"data-activates": "nav-mobile"}, "class": "button-collapse") {
					icon(name: "menu");
				}
			}
		}
	}
}


define header2_admin(tabname:[], tablink:[], tabname1:[], tablink1:[]) {
	div(class: "navbar-fixed ") {
		ul(id: "dropdown1", class: "dropdown-content") {
			li() {
				a1(href: BASE+"slider", text: "Slider");
			}
			li() {
				a1(href: BASE+"report", text: "Reports");
			}
			li() {
				a1(href: BASE+"transc", text: "Transactions");
			}
			li() {
				a1(href: BASE+"tokens", text: "Tokens");
			}
			li() {
				a1(href: HOST+"?logout", text: "Logout");
			}
		}
		nav(class:"white", attr:{role: "container"}) {
			div(class: "nav-wrapper container") {
				a(attr:{id: "logo-container", href: HOST}, class: "brand-logo center") {
					img(attr:{src: "photo/logo4.png"}, class: "responsive-img", style:{"vertical-align": "middle"});
				}
				ul(class: "left hide-on-med-and-down" ) {
					disptabs(tabname: tabname1, tablink: tablink1);
				}
				ul(class: "right hide-on-med-and-down" ) {
					disptabs(tabname: tabname, tablink: tablink);
					li() {
						a1(class: "dropdown-button", text: "&nbsp;"*5+"Profile"+"&nbsp;"*10, data:{activates:"dropdown1"});
						//icon(name: "arrow_drop_down", aclass: "right");
					}
				}
				ul(attr:{id: "nav-mobile"}, "class": "side-nav") {
					disptabs(tabname: tabname1, tablink: tablink1);
					disptabs(tabname: tabname, tablink: tablink);
					li() {
						a1(href: BASE+"slider", text: "Slider");
					}
					li() {
						a1(href: BASE+"report", text: "Reports");
					}
					li() {
						a1(href: BASE+"transc", text: "Transactions");
					}
					li() {
						a1(href: HOST+"?logout", text: "Logout");
					}
				}
				a(attr:{"data-activates": "nav-mobile"}, "class": "button-collapse") {
					icon(name: "menu");
				}
			}
		}
	}
}




define header4() {
	blogurl = "";
	tablink1 = [blogurl];
	tabname1 = ["Blog"];
	if(islogin == None) {
		header2(tablink:[BASE+"chefjoin"], tabname:["Be a Chef"], tablink1: tablink1, tabname1: tabname1);
	} elif (islogin == "u") {
		header2_user(tablink:[BASE+"cart"], tabname:["Cart"], tablink1: tablink1, tabname1: tabname1);
	} elif (islogin == "a") {
		header2_admin(tablink:[BASE+"orders", BASE+"account"], tabname:["Orders", "Accounts"], tabname1: tabname1, tablink1: tablink1);
	}
}


define header3(tabname:[], tablink:[]) {
	div(class: "navbar-fixed ") {
		nav(class:"white", attr:{role: "container"}) {
			div(class: "nav-wrapper container") {
				a(attr:{id: "logo-container", href: BASE}, class: "brand-logo") {
					img(attr:{src: "photo/mylogo1.png"}, class: "circle responsive-img", style:{"vertical-align": "middle"});
				}
				ul(class: "right hide-on-med-and-down" ) {
					li() {
						a(class: "dropdown-button", attr:{"data-activates": "dropdown2"}) {
							print("&nbsp;"*10+"Today, 28th Oct"+"&nbsp;"*10);
						}
					}
					li() {
						a(class: "dropdown-button", attr:{"data-activates": "dropdown1"}) {
							print("&nbsp;"*5+"All"+"&nbsp;"*20);
						}
					}
					disptabs(tabname: tabname, tablink: tablink);
				}
			}
		}
		ul(attr:{id: "dropdown1"}, class: "dropdown-content") {
			foodtype = ["All", "Veg", "Non-Veg"];
			for(i, ii, foodtype) {
				li() {
					a(attr:{href: ""}) {
						print(i);
					}
				}
			}
		}
		ul(attr:{id: "dropdown2"}, class: "dropdown-content") {
			nextdays = ["Today, 26 Oct", "27 Oct", "28 Oct"];
			for(i, ii, nextdays) {
				li() {
					a(attr:{href: ""}) {
						print(i);
					}
				}
			}
		}
	}
}


define l_otp_button() {
	button(class: "btn waves-effect waves-light", attr:{type: "button"}, data:{onclick: "sreq", action: "sendotp", fobj: "$(obj).parent().parent()[0]", restext: "Re-send"}) {
		print("Send OTP");
	}
}


define loginmodal() {
	div(attr:{id: "loginmodal"}, class: "modal") {
		div(class: "modal-content container-fluid") {
			div(class: "row") {
				ul(class: "tabs") {
					disptabs(liclass: "tab col l6", tablink:["#logintab", "#signuptab"], tabname:["Login", "Signup"]);
				}
			}
			div(attr:{id: "logintab"}) {
				form(data:{onsubmit:"sreq", bobj: "", action:"login", res: "ms.reload();", errorh: "error_login"}) {
					errorbox();
					div(class: "row") {
						input3(label: "Phone", icon: "phone", aclass: "col s12 l7 m6", name:"loginphone", dc: "phone");
						div(class: "col l4 m6") {
							l_otp_button();
						}
					}
					div(class: "row"){
						input3(label: "Password or OTP", icon: "vpn_key", aclass: "col s12 l12 m12", name: "loginpass", type: "password", dc: "password1");
					}
					div(class: "row") {
						div(class: "col l6 m6 s6") {
							button(class: "btn waves-effect waves-light", attr:{type: "submit"}) {
								print("Login");
							}
						}
						div(class: "col l6 m6 s6") {
							button(class: "btn waves-effect waves-light", attr: {onclick: 'ms.f1();', type: "button"}) {
								print("Reset Password");
							}
						}
						
					}
				}
				div(class: "row", style: {display: "none"}, id: "resetpasswindow") {
					form(data: {onsubmit: "sreq", bobj: "", action: "rpassword", errorh: "error_login", restext: "Done!"}) {
						errorbox();
						input3(label: "Phone", icon: "phone", aclass: "col s12 l7 m6", name:"phone", dc: "phone");
						div(class: "col l4 m6") {
							button2(text: "Text Me", attr: {type: "submit"});
						}
					}
				}
			}

			div(attr:{id: "signuptab"}) {
				form(data:{onsubmit:"sreq", bobj: "", action:"signup", res: "ms.reload();", errorh: "error_login"}) {
					errorbox();
					div(class: "row") {
						input3(label: "Phone number", icon: "phone", aclass: "col s12 l7 m6", name:"signupphone", dc: "phone");
						div(class: "col l4 m6") {
							l_otp_button();
						}
					}
					div(class: "row"){
						input3(label: "Choose Password", icon: "vpn_key", aclass: "col s12 l6 m6", name: "signuppass", type:"password", dc: "password1");
						input3(label: "OTP", icon: "vpn_key", aclass: "col s12 l6 m6", name: "signupotp", type: "password", dc: "otp");
					}
					div(class: "row"){
						input3(label: "Name", icon: "account_circle", aclass: "col s12 l12 m12", name: "signupname");
					}
					div(class: "row") {
						div(class: "col") {
							button(class: "btn waves-effect waves-light", attr:{type: "submit"}) {
								print("Signup");
							}
						}
					}
				}
			}

		}
	}
}


define profilea1(uid: None, class: None) {
	a1(text: text, href: BASE+"profile?uid="+uid, class: class);
}

define account_admin() {
	div(attr:{align: "center"}) {
		height(val: 20);
		textdiv(text: "Hey Admin,\n you are welcome", font: "20px");
		height(val: 50);
	}
	div(attr:{align: "center"}) {
		button2(text: "RR Lunch", data:{onclick: "sreq", action: "rrorder"}, datas: {"lord": "l"});
		button2(text: "RR Dinner", data:{onclick: "sreq", action: "rrorder"}, datas: {"lord": "d"});
	}
	div() {
		height(val: 20);
		textdiv(text: "Add new Admins", font: "20px");
		height(val: 50);
		form(data:{onsubmit: "sreq", bobj: "", action: "createadmin", restext: "Created", res: "ms.reload();", errorh: "error_login"}) {
			errorbox();
			input1(label: "Phone number", id: "phone", dc: "phone");
			input1(label: "Choose password", id: "password", type: "password");
			button1(name: "Create", attr: {type: "submit"});
		}
	}
	br();
	table(class: "bordered striped centered highlight") {
		thead() {
			tr() {
				for(i, ["UserID", "Name", "Email", "Phone", "User Type"]) {
					th() {
						print(i);
					}
				}
			}
		}
		tbody() {
			for(i, ii, users) {
				tr() {
					for(jjj, jj, ["id", "name", "email", "phone", "typetext"]) {
						j = i[jjj];
						td() {
							if( (jjj=="name") && (i["type"] == "c") ) {
								profilea1(text:j, uid: i["id"]);
							} else {
								print(j);
							}
						}
					}
					td() {
						button1(name: (i["conf"] ? "UnBlock": "Block"), datas:{uid: i['id'], isblock: (i["conf"] != None)}, data:{onclick: "sreq", action: "blockunblock", restext: "Done!", res: "ms.reload();"});
					}
					td() {
						button1(name: "Delete", datas:{uid: i['id']}, data:{onclick: "sreq_confirm", action: "deleteaccount", restext: "Done!", res: "ms.reload();", confirm: "Are you sure ?"});
					}
				}
			}
		}
	}
}


define profile_chef_top2() {
	div(class: "row valign-wrapper") {
		div(class: "col l3", attr:{align: "center"}) {
			div() {
				circleimg(src: uinfo["profilepic"]);
			}
			if(canedit) {
				form(attr:{enctype: "multipart/form-data", method: "post"}) {
					a1(text: "Upload Profile Pic", attr:{onclick: 'uploadfile(this, "profilepic");'});
				}
			}
			div() {
				textdiv(text: "Chef "+uinfo["name"], font: "25px", fontw: "500");
				div(class: "row") {
					div(class: "col l12 m12 s12") {
						textdiv(text:platedelivered, fontw:600);
						textdiv(text: "Plates Delivered");
					}
					// div(class: "col l6") {
					// 	textdiv(text: 56, fontw:600);
					// 	textdiv(text: "People reviewed");
					// }
				}
			}
		}
		div(class: "col l8 offset-l1") {
			textdiv(font:"25px", text:"About "+uinfo["name"], fontw:600);
			if(canedit) {
				a1(text: "Edit", attr:{"onclick": "ms.showtextarea(this);"});
				div(class: 'edittext', style: {display: "none"}) {
					form(data: {onsubmit:"sreq", bobj: "", action:"saveaboutinfo", res: "ms.reload();"}) {
						input(attr: {type: "hidden", name: "chefid", value: uid});
						textarea(attr:{name: "aboutus"}, class: "materialize-textarea") {
							print(uinfo["aboutus"]);
						}
						button1(name: "Save", attr:{type: "submit"});
					}
				}
			}
			textdiv(font:"16px", text: uinfo["aboutus"]);
			div() {
				if(canedit) {
					b() {
						print("Address: ");
					}
					print(uinfo["address"]);
				}
				if(islogin == 'a') {
					a1(text: "Edit", attr:{"onclick": "ms.shownext(this);"});
					form(data:{onsubmit:"sreq", bobj: "", action:"change_address", res: "ms.reload();", errorh: "error_login"}, style: {display: "none"}) {
						errorbox();
						div(class: "row") {
							hidinp(name: "cid", value: uinfo["id"]);
							input1(label: "Address, Choose from google", id: "gaddress", attr:{onkeydown: "return notenterkey(event);"});
							input1(label: "House number", id: "address");
						}
						div() {
							button1(name: "Submit", attr:{type: "submit"});
						}
					}
				}
			}
		}
	}
}


define profile_chef() {
	div(class: "container-fluid") {
		div(class: "row") {
			div(class: "col l10 offset-l1 s10 m10 offset-s1 offset-m1") {
				profile_chef_top2();
				div(class: "msdivider");

				div(class: "container-fluid") {
					div(class: "row") {
					}
				}
				if(canedit) {
					div(class: "container-fluid") {
						div(class: "row") {
							div() {
								ul(class: "tabs") {
									disptabs(liclass: "tab col s2", tabname: ["All Dishes"]+ day5times["textl"], tablink: ["#alldishes"]+ day5times["tabkeys1"]);
								}
							}
							div(class: "") {
								div(attr:{id: "alldishes"}) {
									height(val:20);
									if(viewtype == "a") {
										button1(name: "Add a New Dish", data: {onclick: "slideform"});
										form(style: {display: "none"}, attr:{enctype: "multipart/form-data", method: "post"}) {
											div(class: "row") {
												input(attr:{type:"hidden", name: "cid", value: uid });
												input2(label: "Title of Dish", aclass: "col s12 l4 m4", id:"dishtitle");
												input2(label: "Price of Dish", aclass: "col s12 l4 m4", id:"dishprice");
												select2(tlist: config["foodtype"].values, dclass: "col l3 s12 m4", class: "browser-default", vlist: config["foodtype"].keys, name: "isveg");
											}
											div(class: "row"){
												textarea(class: "materialize-textarea", attr:{name: "descp", placeholder: "Dish Description"});
											}
											div(class: "row") {
												div(class: "file-field input-field") {
													div(class: "btn") {
														span() {
															print("Upload Image");
														}
														input(attr:{type:"file", name: "dishpic"});
													}
													div(class: "file-path-wrapper") {
														input(class: "file-path-validate", attr:{type: "text"});
													}
												}
											}
											div(class: "row") {
												div(class: "col") {
													button(class: "btn waves-effect waves-light", attr:{type: "submit", name:"adddish"}) {
														print("Add");
													}
												}
											}					
										}
									}

									div(class: "row", attr:{align: "center"}) {
										for(i, dispdata) {
											dispfood(dishinfo: i) ;
										}
									}
								}
								for(i, ii, day5times["tabkeys"]) {
									div(attr:{id: i}) {
										div(class: "row") {
											table(class: "bordered") {
												thead() {
													for(j, ["Title", "Price", "Booked For Lunch", "Booked for Dinner"]) {
														th() {
															print(j);
														}
													}
												}
												for(j, jj, dispdata) {
													tr() {
														th() {
															print((j["title"]+"").gchars);
														}
														th() {
															print(j["price"]);
														}
														th() {
															input1(label: "Plate Limit ("+j["ollimit"+ii]+" Booked)", id: "lunch_"+jj+"_"+ii, data:{dishid: j["id"], day:ii}, iclass: "numplatelimit", value: j["llimit"+ii], disabled: block_today_menu[ii][0]);
														}
														th() {
															input1(label: "Plate Limit ("+j["odlimit"+ii]+" Booked)", id: "dinner_"+jj+"_"+ii, data:{dishid: j["id"], day: ii}, iclass: "numplatelimit", value: j["dlimit"+ii], disabled: block_today_menu[ii][1]);
														}
													}
												}
											}
											div() {
												if(dispdata.len != 0) {
													button1(name: "Save", data:{action: "savedaymenu", "onclick": "sreq", params: "ms.getnumlimit("+ii+")"}, datas:{datetime: day5times["timel"][ii], cid: uid});
												}
											}
										}
									}
								}
							}
						}
					}
				}
				div(attr: {align: "center"}, style:{margin:"20px"}) {
					textdiv(text: "Dishes Serving today", font: "25px");
				}
				div(class: "row", attr:{align: "center"}) {
					for(i, dispdata) {
						if( (i["llimit0"] > 0) || (i["dlimit0"] > 0) ) {
							dispfood(dishinfo: i) ;
						}
					}
				}
			}
		}
	}
}


define footer1() {
	div(class: "row blue-grey lighten-4", style: {"margin-bottom": "-10px", padding: "8px"}) {
		div(class: "col s4 m4 l4 center") {
			textdiv1(style: {"font-family": "Gotham-Bold"}) {
				print("Social Media");
			}
			div() {
				footer_icons = ["photo/facebook_icon1.png", "photo/twitter_icon1.png", "photo/linkedin1.png", "photo/instagram1.png"];
				for(i, 4) {
					resimg(src: footer_icons[i], style: {margin: "3px"}, aclass: "cursp");
				}
			}
		}
		div(class: "col s4 m4 l4 center") {
			textdiv1(style: {"font-family": "Gotham-Bold"}) {
				print("Help");
			}
			ul(style: {"margin-top": "0px"}) {
				li() {
					a1(text: "About us", attr:{ "onclick": '$("#aboutus").openModal();'});
				}
				li() {
					a1(text: "Contact us", attr: {onclick: '$("#contactusform").openModal();'});
				}
			}
		}
		div(class: "col s4 m4 l4 center") {
			textdiv1(style: {"font-family": "Gotham-Bold"}) {
				print("Legal");
			}
			ul(){
				li() {
					a1(text: "Company Policies, Terms and Conditions", attr:{ "onclick": '$("#policy").openModal();'});
				}
			}
		}
	}
	div(class: "row blue-grey lighten-3 footer-copyright", style: {"margin-bottom": "-10px", "padding": "8px"}) {
		div(class: "col l12 s12 m12 center") {
			print("&copy; Copyright 2016 KurryBox");
		}
	}
}


define contactus_form() {
	div(class: "row") {
		div(class: "col s12 l12 m12") {
			h3(class: "grey-text text-darken-4") {
				print("Contact US");
			}
		}
		div(class: "col s12 l6 m6") {
			h5(class: "grey-text text-darken-2") {
				print("Mail");
				icon(name: "mail", aclass: "tiny");
			}
			div(class: "grey-text") {
				print("ContactUs@kurrybox.in");
			}
			h5(class: "grey-text text-darken-2") {
				print("Call");
				icon(name: "call", aclass: "tiny");
			}
			div(class: "grey-text") {
				print("+91 9821147004");
			}
		}
	}
}

