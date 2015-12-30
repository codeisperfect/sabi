main2(js:[]) {
	header4();
	div(class: "container") {
		h3() {
			print("Upload Offer Sliders");
		}
		form(attr:{enctype: "multipart/form-data", method: "post"}) {
				a1(text: "Upload Offer Slider", attr:{onclick: 'uploadfile(this, "offersliders");'});
				br();
				span() {
					print("Best Slider: 900*254 px, even if it not of that size, It will be forcefully converted to required size.");
				}
		}
		br();br();
		div() {
			for(i, images) {
				div("class": "row") {
					div(class: "col l8 s4 m4") {
						img(attr: {src: i["image"]}, "class": "responsive-img");
					}
					div(class: "col l4 s4 m4") {
						button2(text: "Delete", datas: {id: i["id"]}, data: {action: "slider_delete", onclick: "sreq", res: "ms.reload();"});
						button2(text: "MoveTop", datas: {id: i["id"]}, data: {action: "slider_movetop", onclick: "sreq", res: "ms.reload();"});
					}
				}
				hr();
			}
		}
	}
}
