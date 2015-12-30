main2(js:[], htmlstyle:{}) {
	div() {
		header4();
		div(class: "container-fluid") {
			div(class: "row") {
				textdiv(text: "Transactions", class: "bigtext");
				button2(text: "Export", attr: {type: "button"}, data: {onclick: "sreq", action: "export_transc", res: "ms.exportp(data);"});
			}
			table() {
				thead() {
					tr() {
						for(i, ["PaymentID", "Price Amount", "Discount", "Amount Paid", "PayuMoneyID", "Bank_Ref_Num", "txnid", "Bank", "Order IDs", "Reciept"]) {
							th() {
								print(i);
							}
						}				
					}
				}
				tbody() {
					for(i, ii, uorders) {
						tr() {
							td() {
								print(i["id"]);
							}
							td() {
								print("Rs. "+i["price_amount"]);
							}
							td() {
								print("Rs. "+i["discount"]);
							}
							td() {
								print("Rs. "+i["net_amount_debit"]);
							}
							td() {
								print(i["payuMoneyId"]);
							}
							td() {
								print(i["bank_ref_num"]);
							}
							td() {
								print(i["txnid"]);
							}
							td() {
								print(i["bankcode"]);
							}
							td() {
								print(i["orderids"]);
							}
							td() {
								a1(href: HOST+i["reciptfile"], text: "Reciept");
							}
							td() {
								a1(href: HOST+i["reciptpdf"], text: "RecieptPdf");
							}
						}
					}
				}
			}
		}
	}
}

