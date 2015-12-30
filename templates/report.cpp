main2(js:["js/report.js?reload"], htmlstyle:{"overflow-y": "scroll"}) {
	if(!showonlymain) {
		header4();
		report_header();
	}
	div(class: "container-fluid") {
		if(report == "orders") {
			div(class: "row") {
				textdiv(text: "Orders", class: "bigtext");
			}
			div(class: "row") {
				form() {
					select2(tlist: chefs[1], vlist: chefs[0], toptext: "All Chef", name: "chefid", dclass: "col l2 s6 m2", selected: chefid);
					select2(tlist: dayweeks[1], vlist: dayweeks[0], name: "dayweeks", toptext: "", dclass: "col l2 s6 m2");
					select2(tlist: ["Delivered", "Failed"], vlist: ['d', 'f'], name: "isdel", toptext: "Status", dclass: "col l2 s6 m2", selected: isdel);
					input3(label: "StartDate",aclass: "col s6",  type: "date", dc: "simple", aclass: "col s6 l2 m3", iclass: "datepicker", value: startdatetext, name: "startdate");
					input3(label: "EndDate",aclass: "col s6",  type: "date", dc: "simple", aclass: "col s6 l2 m3", iclass: "datepicker", value: enddatetext, name: "enddate");
					div(class: "col l2") {
						button2(text: "Filter", attr: {type: "submit"});
					}
				}
			}
			div(class: "row") {
				div(class: "col l2") {
					button2(text: "Export", attr: {type: "button"}, data: {onclick: "sreq", action: "export_orders", res: "ms.exportp(data);"}, datas: {"startdatetext": startdatetext, "enddatetext": enddatetext, chefid: chefid, isdel: isdel});
				}
			}
			div(class: "row") {
				textdiv2() {
					print("Total Amount: ");
					icon1(img: "photo/inr2.png");
					print(totalprice);
				}
			}
			orderl_adminreport(orderl: orderl);
		} else if(report == "menu") {

			div(class: "row") {
				textdiv(text: "Menu", class: "bigtext");
			}
			if(!showonlymain) {
				div(class: "row") {
					form() {
						hidinp(name: "report", value: "menu");
						select2(tlist: chefs[1], vlist: chefs[0], toptext: "All Chef", name: "cid", dclass: "col l2 s6 m2", selected: cid);
						input3(label: "Date",aclass: "col s6",  type: "date", dc: "simple", aclass: "col s6 l2 m3", iclass: "datepicker", value: datetext, name: "date");
						div(class: "col l2") {
							button2(text: "Filter", attr: {type: "submit"});
						}
						div(class: "col l2") {
							button2(text: "Export", attr: {type: "button"}, data: {onclick: "sreq", action: "export_menu", res: "ms.exportp(data);", params: "ms.f3()"});
						}
					}
				}
			}
			div(class: "row") {
				for(i, dishes) {
					dispfood1(dishinfo: i);
				}
			}
		}
	}
}
