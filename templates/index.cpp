main2(js:["js/index.js?reload"]) {
	header4();
	div(attr:{id: "googlemap"});
	div(class: "parallax-container", id: "index-banner") {
		div(class: "section no-pad-bot") {
			div(class: "container valign-wrapper", style: {height: "300px"}) {
				div(class: "valign", style: {width: "100%"}) {
					div(class: "row") {
						div("class": "col l8 offset-l2 m12 s12") {
							div(class: "card-panel grey lighten-5 z-depth-1 ", attr:{align: "center"}) {
								div() {
									b(color: "black", style: {"font-size": "25px"}) {
										print("Awesome Home Food");
									}
								}
								div() {
									b(color: "black", style: {"font-size": "25px"}) {
										print("Near You");
									}
								}
								div(style: {"width": "20%", "border-bottom": "solid black 5px", "min-height": "2px", "margin-top": "10px", "margin-bottom": "10px"});
								div() {
									b(color: "black", style: {"font-size": "16px"}) {
										print("Fresh Ingredients, Daily Menus");
									}
								}
								div() {
									b(color: "black", style: {"font-size": "16px"}) {
										print("No Commitment, No Fuss");
									}
								}
							}
						}
					}
				}
			}
		}
		div(class: "parallax") {
			img(attr: {alt: "Food", src: "photo/pic_spice.jpg"});
		}
	}


	div(class: "container-fluid") {
		height(val: 30);
		div(class: "center") {
			textdiv2(text: "HOW IT WORKS", font: "30px", fontw: None, style: {"font-family": "Gotham-Bold"});
			div(style: {"width": "90%", "margin": "auto", "border-bottom": "solid #ccc 1px"});
		}
		height(val: 20);
		div(class: "row") {
			hww_icons = ['photo/hww4_t.png', 'photo/hww3_t.png', 'photo/hww1_t.png', 'photo/hww4_t.png'];
			hww_texttitle = ["Search Kurrybox", "Chef Cooks", "Free Home Delivery"];
			hww_texts = ["You search kurrybox.in and find who's cooking within 5 km of your current location & book a Meal.", "Our Awesome Home Chef cooks delicacy from her home kitchen.", "We do lightning fast free delivery in the slot you have selected"];
			for(i, 3) {
				div(class: "col l4 m4 s12 center", style: {"padding-top": "10px"}) {
					div() {
						resimg(src: hww_icons[i]);
					}
					textdiv2(text: hww_texttitle[i], font: "20px");
					div(style: {padding: "10px"}) {
						print(hww_texts[i]);
					}
				}
			}
		}
		height(val: 50);
		footer1();
	}
	div(class: "modal", id: "contactusform", style: {padding: "20px"}) {
		contactus_form();
	}
}

