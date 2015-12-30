#This code is auto generated code, don't Edit it 
outpvar.cur.addfcdata("main2");
if (not(ginp["showonlymain"])): 
  outpvar.cur.fcalldata["main2"].cur.addfcdata("header4");
  outpvar.cur.fcalldata["main2"].addchilds(newtag_header4(cod([]), ginp, outpvar.cur.fcalldata["main2"].cur.fcalldata["header4"].root.content).root.content);
  outpvar.cur.fcalldata["main2"].cur.addfcdata("report_header");
  outpvar.cur.fcalldata["main2"].addchilds(newtag_report_header(cod([]), ginp, outpvar.cur.fcalldata["main2"].cur.fcalldata["report_header"].root.content).root.content);
outpvar.cur.fcalldata["main2"].open(htmlnode("div", extentattrs(cod([("class", "container-fluid")]))));
if (int((ginp["report"] == "orders"))): 
  outpvar.cur.fcalldata["main2"].open(htmlnode("div", extentattrs(cod([("class", "row")]))));
  outpvar.cur.fcalldata["main2"].cur.addfcdata("textdiv");
  outpvar.cur.fcalldata["main2"].addchilds(newtag_textdiv(cod([("text", "Orders"), ("class", "bigtext")]), ginp, outpvar.cur.fcalldata["main2"].cur.fcalldata["textdiv"].root.content).root.content);
  outpvar.cur.fcalldata["main2"].close();
  outpvar.cur.fcalldata["main2"].open(htmlnode("div", extentattrs(cod([("class", "row")]))));
  outpvar.cur.fcalldata["main2"].open(htmlnode("form", extentattrs(cod([]))));
  outpvar.cur.fcalldata["main2"].cur.addfcdata("select2");
  outpvar.cur.fcalldata["main2"].addchilds(newtag_select2(cod([("tlist", ginp["chefs"][1]), ("vlist", ginp["chefs"][0]), ("toptext", "All Chef"), ("name", "chefid"), ("dclass", "col l2 s6 m2"), ("selected", ginp["chefid"])]), ginp, outpvar.cur.fcalldata["main2"].cur.fcalldata["select2"].root.content).root.content);
  outpvar.cur.fcalldata["main2"].cur.addfcdata("select2");
  outpvar.cur.fcalldata["main2"].addchilds(newtag_select2(cod([("tlist", ginp["dayweeks"][1]), ("vlist", ginp["dayweeks"][0]), ("name", "dayweeks"), ("toptext", ""), ("dclass", "col l2 s6 m2")]), ginp, outpvar.cur.fcalldata["main2"].cur.fcalldata["select2"].root.content).root.content);
  outpvar.cur.fcalldata["main2"].cur.addfcdata("select2");
  outpvar.cur.fcalldata["main2"].addchilds(newtag_select2(cod([("tlist", ["Delivered", "Failed"]), ("vlist", ["d", "f"]), ("name", "isdel"), ("toptext", "Status"), ("dclass", "col l2 s6 m2"), ("selected", ginp["isdel"])]), ginp, outpvar.cur.fcalldata["main2"].cur.fcalldata["select2"].root.content).root.content);
  outpvar.cur.fcalldata["main2"].cur.addfcdata("input3");
  outpvar.cur.fcalldata["main2"].addchilds(newtag_input3(cod([("label", "StartDate"), ("aclass", "col s6"), ("type", "date"), ("dc", "simple"), ("aclass", "col s6 l2 m3"), ("iclass", "datepicker"), ("value", ginp["startdatetext"]), ("name", "startdate")]), ginp, outpvar.cur.fcalldata["main2"].cur.fcalldata["input3"].root.content).root.content);
  outpvar.cur.fcalldata["main2"].cur.addfcdata("input3");
  outpvar.cur.fcalldata["main2"].addchilds(newtag_input3(cod([("label", "EndDate"), ("aclass", "col s6"), ("type", "date"), ("dc", "simple"), ("aclass", "col s6 l2 m3"), ("iclass", "datepicker"), ("value", ginp["enddatetext"]), ("name", "enddate")]), ginp, outpvar.cur.fcalldata["main2"].cur.fcalldata["input3"].root.content).root.content);
  outpvar.cur.fcalldata["main2"].open(htmlnode("div", extentattrs(cod([("class", "col l2")]))));
  outpvar.cur.fcalldata["main2"].cur.addfcdata("button2");
  outpvar.cur.fcalldata["main2"].addchilds(newtag_button2(cod([("text", "Filter"), ("attr", cod([("type", "submit")]))]), ginp, outpvar.cur.fcalldata["main2"].cur.fcalldata["button2"].root.content).root.content);
  outpvar.cur.fcalldata["main2"].close();
  outpvar.cur.fcalldata["main2"].close();
  outpvar.cur.fcalldata["main2"].close();
  outpvar.cur.fcalldata["main2"].open(htmlnode("div", extentattrs(cod([("class", "row")]))));
  outpvar.cur.fcalldata["main2"].open(htmlnode("div", extentattrs(cod([("class", "col l2")]))));
  outpvar.cur.fcalldata["main2"].cur.addfcdata("button2");
  outpvar.cur.fcalldata["main2"].addchilds(newtag_button2(cod([("text", "Export"), ("attr", cod([("type", "button")])), ("data", cod([("onclick", "sreq"), ("action", "export_orders"), ("res", "ms.exportp(data);")])), ("datas", cod([("startdatetext", ginp["startdatetext"]), ("enddatetext", ginp["enddatetext"]), ("chefid", ginp["chefid"]), ("isdel", ginp["isdel"])]))]), ginp, outpvar.cur.fcalldata["main2"].cur.fcalldata["button2"].root.content).root.content);
  outpvar.cur.fcalldata["main2"].close();
  outpvar.cur.fcalldata["main2"].close();
  outpvar.cur.fcalldata["main2"].open(htmlnode("div", extentattrs(cod([("class", "row")]))));
  outpvar.cur.fcalldata["main2"].cur.addfcdata("textdiv2");
  outpvar.cur.fcalldata["main2"].cur.fcalldata["textdiv2"].addtext("Total Amount: ");
  outpvar.cur.fcalldata["main2"].cur.fcalldata["textdiv2"].cur.addfcdata("icon1");
  outpvar.cur.fcalldata["main2"].cur.fcalldata["textdiv2"].addchilds(newtag_icon1(cod([("img", "photo/inr2.png")]), ginp, outpvar.cur.fcalldata["main2"].cur.fcalldata["textdiv2"].cur.fcalldata["icon1"].root.content).root.content);
  outpvar.cur.fcalldata["main2"].cur.fcalldata["textdiv2"].addtext(ginp["totalprice"]);
  outpvar.cur.fcalldata["main2"].addchilds(newtag_textdiv2(cod([]), ginp, outpvar.cur.fcalldata["main2"].cur.fcalldata["textdiv2"].root.content).root.content);
  outpvar.cur.fcalldata["main2"].close();
  outpvar.cur.fcalldata["main2"].cur.addfcdata("orderl_adminreport");
  outpvar.cur.fcalldata["main2"].addchilds(newtag_orderl_adminreport(cod([("orderl", ginp["orderl"])]), ginp, outpvar.cur.fcalldata["main2"].cur.fcalldata["orderl_adminreport"].root.content).root.content);
elif (1): 
  if (int((ginp["report"] == "menu"))): 
    outpvar.cur.fcalldata["main2"].open(htmlnode("div", extentattrs(cod([("class", "row")]))));
    outpvar.cur.fcalldata["main2"].cur.addfcdata("textdiv");
    outpvar.cur.fcalldata["main2"].addchilds(newtag_textdiv(cod([("text", "Menu"), ("class", "bigtext")]), ginp, outpvar.cur.fcalldata["main2"].cur.fcalldata["textdiv"].root.content).root.content);
    outpvar.cur.fcalldata["main2"].close();
    if (not(ginp["showonlymain"])): 
      outpvar.cur.fcalldata["main2"].open(htmlnode("div", extentattrs(cod([("class", "row")]))));
      outpvar.cur.fcalldata["main2"].open(htmlnode("form", extentattrs(cod([]))));
      outpvar.cur.fcalldata["main2"].cur.addfcdata("hidinp");
      outpvar.cur.fcalldata["main2"].addchilds(newtag_hidinp(cod([("name", "report"), ("value", "menu")]), ginp, outpvar.cur.fcalldata["main2"].cur.fcalldata["hidinp"].root.content).root.content);
      outpvar.cur.fcalldata["main2"].cur.addfcdata("select2");
      outpvar.cur.fcalldata["main2"].addchilds(newtag_select2(cod([("tlist", ginp["chefs"][1]), ("vlist", ginp["chefs"][0]), ("toptext", "All Chef"), ("name", "cid"), ("dclass", "col l2 s6 m2"), ("selected", ginp["cid"])]), ginp, outpvar.cur.fcalldata["main2"].cur.fcalldata["select2"].root.content).root.content);
      outpvar.cur.fcalldata["main2"].cur.addfcdata("input3");
      outpvar.cur.fcalldata["main2"].addchilds(newtag_input3(cod([("label", "Date"), ("aclass", "col s6"), ("type", "date"), ("dc", "simple"), ("aclass", "col s6 l2 m3"), ("iclass", "datepicker"), ("value", ginp["datetext"]), ("name", "date")]), ginp, outpvar.cur.fcalldata["main2"].cur.fcalldata["input3"].root.content).root.content);
      outpvar.cur.fcalldata["main2"].open(htmlnode("div", extentattrs(cod([("class", "col l2")]))));
      outpvar.cur.fcalldata["main2"].cur.addfcdata("button2");
      outpvar.cur.fcalldata["main2"].addchilds(newtag_button2(cod([("text", "Filter"), ("attr", cod([("type", "submit")]))]), ginp, outpvar.cur.fcalldata["main2"].cur.fcalldata["button2"].root.content).root.content);
      outpvar.cur.fcalldata["main2"].close();
      outpvar.cur.fcalldata["main2"].open(htmlnode("div", extentattrs(cod([("class", "col l2")]))));
      outpvar.cur.fcalldata["main2"].cur.addfcdata("button2");
      outpvar.cur.fcalldata["main2"].addchilds(newtag_button2(cod([("text", "Export"), ("attr", cod([("type", "button")])), ("data", cod([("onclick", "sreq"), ("action", "export_menu"), ("res", "ms.exportp(data);"), ("params", "ms.f3()")]))]), ginp, outpvar.cur.fcalldata["main2"].cur.fcalldata["button2"].root.content).root.content);
      outpvar.cur.fcalldata["main2"].close();
      outpvar.cur.fcalldata["main2"].close();
      outpvar.cur.fcalldata["main2"].close();
    outpvar.cur.fcalldata["main2"].open(htmlnode("div", extentattrs(cod([("class", "row")]))));
    for i in forlist(ginp["dishes"], False ) :
      outpvar.cur.fcalldata["main2"].cur.addfcdata("dispfood1");
      outpvar.cur.fcalldata["main2"].addchilds(newtag_dispfood1(cod([("dishinfo", i)]), ginp, outpvar.cur.fcalldata["main2"].cur.fcalldata["dispfood1"].root.content).root.content);
    outpvar.cur.fcalldata["main2"].close();
outpvar.cur.fcalldata["main2"].close();
outpvar.addchilds(newtag_main2(cod([("js", ["js/report.js?reload"]), ("htmlstyle", cod([("overflow-y", "scroll")]))]), ginp, outpvar.cur.fcalldata["main2"].root.content).root.content);