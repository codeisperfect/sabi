$( document ).ready(function(){
	$(function () {
	  $('[data-toggle="tooltip"]').tooltip()
	});
	$('.dropdown-menu').click(function(e) {
		e.stopPropagation();
	});
	$(".dropdown-content").on("click", function(e){
		e.stopPropagation();
	});
	runonload();
	mylib();
});




function runonload() {
	$('.materialboxed').materialbox();
	$('.slider').slider({
		full_width: true,
		height:250,
		transition:400,
		interval:3500
	});
	$(".collapsible_sub").collapsible();
	$('.datepicker').pickadate({
		selectMonths: true,
		selectYears: 130,
		startDate:'1-1-1950',
		format: 'd-m-yyyy'
	});
	$(".dropdown-button").dropdown({hover: false});
	$('.dropdown-content').click(function(e) {
		e.stopPropagation();
	});
	$(".button-collapse").sideNav();
	$('.parallax').parallax();
	$('select').material_select();

	$('.modal-trigger').leanModal();
	$('.collapsible').collapsible({
			accordion : false // A setting that changes the collapsible behavior to expandable instead of the default accordion style
		});
}
