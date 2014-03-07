$( document ).ready(function() {
  // Section class selector
  (function setSectionClass() {
    var pathname = window.location.pathname;
    if (pathname.match(/\/general\/|\/general.html/)) {
      $("body").addClass("general");
    } else if (pathname.match(/\/arduino\/|\/arduino.html/)) {
      $("body").addClass("arduino");
    } else if (pathname.match(/\/raspberrypi\/|\/raspberrypi.html/)) {
      $("body").addClass("raspberrypi");
    } else if (pathname.match(/\/c\+\+\/|\/c\+\+\.html/)) {
      $("body").addClass("cpp");
    } else if (pathname.match(/\/nodejs\/|nodejs.html/)) {
      $("body").addClass("nodejs");
    } else if (pathname.match(/\/python\/|python.html/)) {
      $("body").addClass("python");
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
  var tabbed = $(".tabbed");
  if (tabbed.length > 0) {
    var first_tab = tabbed.first();
    console.log(first_tab);
    first_tab.addClass("current");
    var titles = tabbed.find("h2");
    var tabs_html = "";
    for (var t=0; t<titles.length; t++) {
      var class_name = (t==0) ? "tab current" : "tab";
      tabs_html += "<span class='" + class_name + "'>" + $(titles[t])
        .clone() //clone the element
        .children() //select all the children
        .remove()   //remove all the children
        .end()  //again go back to selected element
        .text() + "</span>";
    };
    first_tab.before($("<div class='tabs'>" + tabs_html + "</div>"));
    $(".tab").click(function() {
      var this_tab = $(this);
      var index = $(".tab").removeClass("current").index(this_tab);
      this_tab.addClass("current");
      var sections = $(".tabbed").removeClass("current");
      $(sections[index]).addClass("current");
    });
  };
});
