main_rec() {
	div(style: {width: "680px", "overflow": "hidden", "margin": "auto", border: "solid #ccc 1px"}) {
		div(style: {height: "180px;", "overflow": "hidden"}) {
			img(attr: {src: HOST+"photo/recipt/photo3.png"});
		}
		div(style: {}) {
			div(style: {float: "left", width: "50%"}) {
				div(style: {"margin-left": "30px", "margin-top": "60px"}) {
					b(style:{"font-size": "20px", "color": "#26A69A"}) {
						print(uname+",");
					}
					br();
					span(style:{"font-size": "18px"}) {
						print("Thank You for shopping at kurrybox.in");
					}
					br();br();
					b(style:{"font-size": "18px", "color": "#26A69A"}) {
						print("Your Order Will be Delivered At: ");
					}
					br();
					i(style:{"font-size": "15px"}) {
						print(address);
						br();
						print("Phone: ");
						print(phone);
					}
				}
			}
			div(style: {float: "left", width: "50%"}, attr: {align: "right"}) {
				div(style: {"margin-right": "30px", "margin-top": "20px"}) {
					div(style: {"margin-right": "10px"}) {
						img(attr: {src: HOST+"photo/logo4.png"});
					}
					br();
					div() {
						table() {
							tr() {
								td(style:{"font-weight": 900, "font-size": "18px", "color": "#26A69A", padding: "5px"}, attr:{align: "right", valign: "top"}) {
									print("Orderd At: ");
								}
								td(style:{"font-size": "18px" }) {
									print(orderedat);
								}
							}
							tr() {
								td(style:{"font-weight": 900, "font-size": "18px", "color": "#26A69A", padding: "5px"}, attr:{align: "right"}) {
									print("Order ID: ");
								}
								td(style:{"font-size": "18px" }) {
									print(uorderid);
								}
							}
							tr() {
								td(style:{"font-weight": 900, "font-size": "18px", "color": "#26A69A", padding: "5px"}, attr:{align: "right"}) {
									print("Payment ID: ");
								}
								td(style:{"font-size": "18px" }) {
									print(paymentid);
								}
							}
						}
					}
				}
			}
			div(style: {clear: "both"});
		}
		br();
		div(style: {margin: "30px", "margin-top": "10px"}) {
			table(attr: {cellspacing: "0", cellpadding:"0", border: 0}) {
				width = [10, 280, 200, 80, 80];
				tr() {
					titles = ["S.No.", "Dish", "Due On", "Price*Qty", "Amount"];
					for(i, ii, titles) {
						td(style: {padding: "15px 3px", "border": "solid #26A69A 1px", "margin": "0px", "background-color": "#26A69A", color: "white", "font-weight": 900}, attr: {align: "center"}) {
							print(i);
						}
					}
				}
				for(j, jj, olist) {
					tr() {
						titles = [jj+1, "<b>"+j["dishtitle"]+"</b><br>From Chef "+j["chefname"], j["dueon"], j["price"]+"*"+j["numplate"], j["price"]*j["numplate"]];
						for(i, ii, titles) {
							td(style: {padding: "15px 3px", "border": "solid #26A69A 1px", "margin": "0px", width: width[ii]+"px"}, attr: {align: "center"}) {
								print(i);
							}
						}
					}
				}
			}
			if(discount != None) {
				table(attr: {cellspacing: "0", cellpadding:"0", border: 0}) {
					width = [10+280+250+20, 80];
					elms = [["Total Amount: "+"&nbsp;"*2, "Discount: "+"&nbsp;"*2], [totalamount, "-"+discount]];
					for(j, 2) {
						tr() {
							for(i, 2) {
								td(style: {padding: "10px 3px", "border": "solid #26A69A 1px", "margin": "0px", width: width[i]+"px", "font-weight": "800"}, attr: {align: ["right", "center"][i] }) {
									print(elms[i][j]);
								}
							}
						}
					}
				}
			}
			br();
			div(attr: {align: "right"}, style: {"background-color": "#26A69A"}) {
				div(style: {padding: "20px 10px", color: "white", "font-weight": 900}) {
					b(style: {"font-size": "30px"}) {
						print("Total Payment:");
						print("&nbsp;"*5);
						print(" Rs. ");
						print(amount);
					}
				}
			}
			div() {
				br();br();br();
				b(style:{"font-size": "25px", "color": "#26A69A"}) {
					print("Enjoy your meal");
				}
				br();
				i(style:{"font-size": "20px"}) {
					print("Kurrybox Team");
				}
				br();br();
				span(style:{"font-size": "20px"}) {
					print("Contactus@kurrybox.in");
				}
			}
		}
		div(style: {height: "180px;", "overflow": "hidden"}) {
			img(attr: {src: HOST+"photo/recipt/photo4.png"});
		}
	}
}
