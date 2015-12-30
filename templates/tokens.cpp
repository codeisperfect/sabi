main2(js:[]) {
	header4();
	div(class: "container") {
		h3() {
			print("Discount Tokens");
		}
		div(class: "row") {
			div(class: "col s12 l12 m12") {
				print("Token value can be like '45' or '15%' ");
			}
			form(data: {action: "add_token", onsubmit: "sreq", bobj: "", res: "ms.reload();"}) {
				input3(label: "Token", name: "name", aclass: "col s6 l2 m3");
				input3(label: "Token Value", name: "value", aclass: "col s6 l2 m3");
				input3(label: "Start Date", name: "startdate", iclass: "datepicker", aclass: "col s6 l2 m3");
				input3(label: "Expire Date", name: "enddate", iclass: "datepicker", aclass: "col s6 l2 m3");
				select2(tlist: ["Multiple Time", "One Time"], vlist: ["0", "1"], name: "isonetime", dclass: "col s6 l2 m3");
				button2(text: "Add", attr: {type: "submit"});
			}
		}
		br();br();

		table(class: "bordered") {
			thead() {
				tr() {
					for(i, ["Token", "Value", "Start Date", "Expire Date", "Type", ""]) {
						th() {
							print(i);
						}
					}
				}
			}				
			tbody() {
				for(i, tokens) {
					tr() {
						for(j, ["name", "value", "startdatetext", "enddatetext"]) {
							td() {
								print(i[j]);
							}
						}
						td() {
							print(["One Time", "Multiple Time"][i["isonetime"] == "0"]);
						}
						td() {
							button2(text: "delete", data: {action: "delete_token", onclick: "sreq", res: "ms.reload();"}, datas: {name: i["name"]});
						}
					}
				}
			}
		}
	}
}
