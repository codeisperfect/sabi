main2(js:[]) {
	header4();
	div(class: "container") {
		height(val: 100);
		form(attr:{enctype: "multipart/form-data", method: "post"}) {
			div(class: "row") {
				hidinp(name: "dishid", value: id);
				hidinp(name: "cid", value: cid);
				input2(label: "Title of Dish", aclass: "col s12 l4 m4", id:"dishtitle", value: title);
				input2(label: "Price of Dish", aclass: "col s12 l4 m4", id:"dishprice", value: price);
				select2(tlist: config["foodtype"].values, dclass: "col l3 s12 m4", class: "browser-default", vlist: config["foodtype"].keys, name: "isveg", selected: isveg);
			}
			div(class: "row"){
				textarea(class: "materialize-textarea", attr:{name: "descp", placeholder: "Dish Description"}) {
					print(descp);
				}
			}
			div(class: "row") {
				span() {
					print("If you upload newpic, oldpic will be overwritten");
				}
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
					button(class: "btn waves-effect waves-light", attr:{type: "submit", name:"editdish"}) {
						print("Edit");
					}
				}
			}					
		}

	}
}
