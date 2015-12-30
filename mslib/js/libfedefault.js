function mylib() {//Function to be executed, just after loading a page.
	map(function(i) {
		$("*").on(i, function() {
			var alla = dattr(this);
			if(haskey(alla, "on"+i)) {
				var addeda = setifunset(alla, "obj", this);
				return fold(function(x,y){ return !((y==false) || (x == false)); }, mapp(function(x){ return runf(x, addeda); }, spacesplit(alla["on"+i])), true);
			}
		});
	}, ["click", "submit"]);
}
