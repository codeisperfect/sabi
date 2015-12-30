main2(js:["js/menu.js"], htmlstyle:{"overflow-y": "scroll"}) {
	div() {
		header4();
		if(islogin == "a") {
			div(class: "continer") {
				div(class: "row") {
					div(class: "col l8 offset-l2 m10 offset-m1 s12") {
						account_admin(users: users);
					}
				}
			}
		} elif ((islogin == "c") || (islogin == "u")) {
			div(class: "continer") {
				div(class: "row") {
					div(class: "col s12 l6 m6") {
						h3() {
							print("Change password");
						}
						form(data:{onsubmit:"sreq", bobj: "", action:"cpassword", errorh: "error_login", restext: "Changed!"}) {
							errorbox();
							div(class: "row"){
								input3(label: "Old password", aclass: "col s12 l12 m12", name: "oldpass", type: "password", dc: "password1");
							}
							div(class: "row"){
								input3(label: "New password", aclass: "col s12 l12 m12", name: "newpass", type: "password", dc: "password1", id: "password");
							}
							div(class: "row"){
								input3(label: "Repeat new password", aclass: "col s12 l12 m12", type: "password", dc: "password");
							}
							div(class: "row") {
								div(class: "col") {
									button(class: "btn waves-effect waves-light", attr:{type: "submit"}) {
										print("Change");
									}
								}
							}					
						}
					}
				}
			}
		}
	}
}
