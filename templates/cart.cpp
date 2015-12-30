main2(js:["js/cart.js?reload"], htmlstyle:{"overflow-y": "scroll"}) {
	div() {
		header4();
		div(class: "container") {
			div(class: "row") {
				textdiv(text: "My Cart", class: "bigtext");
			}
			div(class: "row") {
				table(class: "bordered") {
					thead() {
						for(i, ["Delivery Date", "Chef", "Meal Type", "Dish", "Price", "No. of plates", "Delivery Slot", "Status"]) {
							th() {
								print(i);
							}
						}
					}
					tbody() {
						for(i, ii, cartl) {
							tr(class: "cartitems", datas:{ datetime: i["datetime"], cid: i["cid"], lord: i["lord"], dishid: i["dishid"]}) {
								td() {
									print(i["datetimetext"]);
								}
								td() {
									profilea1(text: i["name"], uid: i["cid"], class: "chefname");
								}
								td() {
									print({"l": "Lunch", "d": "Dinner"}[i["lord"]]);
								}
								td(attr: {class: "dishtitle"}) {
									print(i["title"]);
								}
								td() {
									icon1(img: "photo/inr2.png");
									span(class: "itemprice") {
										print(i["price"]);
									}
								}
								td() {
									select1(tlist: i["tlist"], aclass: "numitem", attr:{onchange: "settotalprice();"}, selected: i["quantity"]);
								}
								td() {
									select1(tlist: dslots[i["lord"]], aclass: "dslots");
								}
								td() {
									div(style: {color: "red"}, data:{iserror: (i["error"] != "")}) {
										print(i["error"]);
									}
								}
								td() {
									button1(name: "Delete", data: {onclick: "sreq", action: "delfromcart", restext: "Deleted", res: "removerow(obj);"}, datas: {id: i["id"] });
								}
							}
						}
					}
				}
			}
			div(class: "row") {
				div(class: "col l12") {
					span(style: {"font-size": "25px"}) {
						print("Total Price: ");
						span(id: "totalprice") {
							print(100);
						}
						icon1(img: "photo/inr1.png");
					}
				}
				div(class: "col l12") {
					span(style: {"font-size": "18px"}) {
						print("Address: ");
						span() {
							print(address[2]);
						}
					}
					a1(text: "change", href:"", style: {"font-size": "11px"});
				}
			}
			div(class: "row") {
				div(class: "col s12 l12 m12") {
					button2(text: "Use Token", attr: {onclick: "ms.f4(this);"});
				}
			}
			div(class: "row", style: {display: "none"}) {
				form(data: {onsubmit: "sreq", bobj:"", action: "apply_token", res: "ms.f5(data);"}) {
					input3(label: "Token", aclass: "col s6 l3 m3", name: "name");
					div(class: "col s6 l3 m3") {
						button2(text: "Add", attr:{type: "submit"});
					}
				}
			}
			div(class: "row"){
				form(data: {action: "order", onsubmit: "order", bobj: "", restext: "Ordered", errorh: "error_login", "res": 'cartorder(data);'}) {
					errorbox();
					input3(label: "House number", name: "eaddress");
					if(needemail) {
						input3(label: "Email ID", name: "email", dc: "email");
					}
					div(class: "col l12") {
						button1(name: "Order", attr:{type: "submit"});
					}
				}
			}
		}
		div(class: "dnone") {
			textdiv(id: "lat", text: address[0]);
			textdiv(id: "lng", text: address[1]);
		}
	}
}
