
function is_section(section, pathname){
   var path = get_route_with_params(pathname);
   if(path.indexOf(section + "/") == 0){
      return true;
   } 
   if(path == section + ".html" || path == "en/latest/" + section + ".html"){
      return true;
   } 
   return false;
}

function get_route_with_params(pathname){
  //Giving a path with http:// or local path, returns the rest
  var tmp;
  console.log(pathname);
  if(pathname.indexOf("_build/") != -1){
    tmp = pathname.split("_build/")[1];
  }
  else if(pathname.indexOf("://") != -1){
    tmp = pathname.split("://")[1];
  }
  else{
    tmp = pathname;
  }
  
  var index = tmp.indexOf("/");
  return tmp.substring(index + 1);
}

$( document ).ready(function() {


  //Saves the left panel scroll in cookie to restore vertical position on load
  var last_scroll = $.cookie('saved_scroll');
  console.log("LAST SCROLL: " + last_scroll);
  if(last_scroll){
     $(".nav-side").scrollTop(last_scroll);
  }

  $(".biisection").click(function(){
    $.removeCookie('saved_scroll'); 
  });
  $(".menu-vertical a").click(
    function(){
      var saved_scroll = $(".nav-side").scrollTop();
      $.cookie('saved_scroll', saved_scroll);
    }
  );

  // Cheat to show first toctable if not toctable visible
  var visible_menu = false;
  
  $("#lateral_menu_biicode > ul > li").each(function(i) { 
      if($(this).hasClass("current")){
        visible_menu = true;
      }          
  });

  if(!visible_menu){
    $("#lateral_menu_biicode > ul > li:first").addClass("current");
  }


  // Section class selector
  (function setSectionClass() {
    var pathname = window.location.pathname;
    if (is_section("arduino", pathname)) {
      $("body").addClass("arduino");
      $(".arduino.biisection").addClass("current_section");
    } 
    else if (is_section("raspberrypi", pathname)) {
      $("body").addClass("raspberrypi");
      $(".raspberrypi.biisection").addClass("current_section");
    } 
    else if (is_section("c++", pathname)) {
      $("body").addClass("cpp");
      $(".cpp.biisection").addClass("current_section");
    } 
    else if (is_section("nodejs", pathname)) {
      $("body").addClass("nodejs");
      $(".nodejs.biisection").addClass("current_section");
    } 
    else if (is_section("python", pathname)) {
      $("body").addClass("python");
      $(".python.biisection").addClass("current_section");
    } 
    else {
      $("body").addClass("biicode");
    };
  })();
  // Shift nav in mobile when clicking the menu.
  $("[data-toggle='nav-top']").click(function() {
    $("[data-toggle='nav-shift']").toggleClass("shift");
    $("[data-toggle='rst-versions']").toggleClass("shift");
  });
  // Close menu when you click a link.
  $(".menu-vertical .current ul li a").click(function() {
    $("[data-toggle='nav-shift']").removeClass("shift");
    $("[data-toggle='rst-versions']").toggleClass("shift");
  });
  $("[data-toggle='rst-current-version']").click(function() {
    $("[data-toggle='rst-versions']").toggleClass("shift-up");
  });
  $("table.docutils:not(.field-list").wrap("<div class='table-responsive'></div>");


  /* This hack is to display correctly menu items pointing to section tags */
  $(".toctree-l2").click(function() {
    $(".toctree-l2").removeClass("current");
    $(this).addClass("current");
  });
  /* This hack is to display correctly menu items pointing to section tags */
  $(".toctree-l3").click(function() {
    $(".toctree-l3").removeClass("current");
    $(this).addClass("current");
  });
  /* This hack is for including tabs */
  var tabs_sections = $(".tabs-section");
  if (tabs_sections.length > 0) {
    for (var i=0; i<tabs_sections.length; i++) {
      var tabs_group = $(tabs_sections[i]); // current tab container
      var group_class = "tabs-group-" + i;
      tabs_group.addClass(group_class);

      var tabbed = tabs_group.find(".tabs-item");
      tabbed.addClass(group_class);
      var first_tab = tabbed.first();
      first_tab.addClass("current");
      var titles = tabbed.find(".tabs-title");
      var tabs_html = "";
      for (var t=0; t<titles.length; t++) {
        var class_name = (t==0) ? "tab current" : "tab";
        tabs_html += "<span class='" + class_name + "' data-group='" + group_class + "'>" + 
          $(titles[t])
            .clone()    //clone the element
            .children() //select all the children
            .remove()   //remove all the children
            .end()      //again go back to selected element
            .text() + "</span>";
      };
      first_tab.before($("<div class='tabs'>" + tabs_html + "</div>"));
      tabs_group.find(".tab").click(function() {
        var this_tab = $(this);
        var group_class = this_tab.attr("data-group");
        var group = $(".tabs-section."+group_class);
        var index = group.find(".tab").removeClass("current").index(this_tab);
        this_tab.addClass("current");
        var sections = group.find(".tabs-item").removeClass("current");
        $(sections[index]).addClass("current");
      });
    };
  };
});
