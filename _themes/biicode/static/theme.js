/* Check for localStorage support */
function checkLocalStorage() {
  try {
    return 'localStorage' in window && window['localStorage'] !== null;
  } catch (e) {
    return false;
  }
};

$( document ).ready(function() {
  // Section class selector
  (function setSectionClass() {
    var pathname = window.location.pathname;
    if (pathname.match(/\/arduino\/|\/arduino.html/)) {
      $("body").addClass("arduino");
    } else if (pathname.match(/\/raspberrypi\/|\/raspberrypi.html/)) {
      $("body").addClass("raspberrypi");
    } else if (pathname.match(/\/c\+\+\/|\/c\+\+\.html/)) {
      $("body").addClass("cpp");
    } else if (pathname.match(/\/nodejs\/|nodejs.html/)) {
      $("body").addClass("nodejs");
    } else if (pathname.match(/\/python\/|python.html/)) {
      $("body").addClass("python");
    } else {
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
  /* This hack is for navigation 'go back' option inter sections */
  (function goBack() {
    function getSection(path) {
      var section = "biicode";
      if (path.match(/[_build\/html\/|^\/]c\+\+/)) section = "cpp";
      else if (path.match(/[_build\/html\/|^\/]arduino/)) section = "arduino";
      else if (path.match(/[_build\/html\/\^\/]raspberrypi/)) section = "raspberrypi";
      else if (path.match(/[_build\/html\/\^\/]nodejs/)) section = "nodejs"; 
      return section;
    }
    /* Clear local cache if needed (referrer info, only in production) */
    var hostName = window.location.hostname;
    if ((hostName!="") && (hostName!="localhost") && checkLocalStorage()) {
      if (!document.referrer.match("docs.biicode.com"))
        localStorage.clear();
    }
    /* Init function for all page links */
    $("a").click(function(e) {
      var current = getSection(window.location.pathname),
          destination = getSection(this.href);
      if ((current != destination) && checkLocalStorage()) {
        var navData = {
          title: window.document.title.replace(" — [biicode docs]", ""),
          href: window.location.href,
          className: current
        };
        var navigation = [];
        if (localStorage.navigation) navigation = JSON.parse(localStorage.navigation);
        navigation.push(navData);
        localStorage.navigation = JSON.stringify(navigation);
      };
    });
    /* Check if navigation data present, and init go back button */
    if (checkLocalStorage() && (localStorage.navigation)) {
      var navData = JSON.parse(localStorage.navigation).slice(-1)[0];
      if (navData) {
        var backLink = $(".goback").addClass("on").find(".link");
        backLink.html("Back to " + navData.title);
        backLink.attr("data-link", navData.href);
        backLink.addClass(navData.className);
      } else {
        $(".goback").removeClass("on"); // hide button
      };
    };
    /* Back link button */
    $(".goback .link").click(function(e) {
      // clear last navigation element data
      var navigation = JSON.parse(localStorage.navigation);
      navigation.pop();
      localStorage.navigation = JSON.stringify(navigation);
      // redirect window:
      window.location.href = $(this).attr("data-link");
    });
  })();
  /* This hack is for including tabs */
  var tabs_sections = $(".tabs-section");
  if (tabs_sections.length > 0) {
    for (var i=0; i<tabs_sections.length; i++) {
      var tabs_group = $(tabs_sections[i]);
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
      $(".tab").click(function() {
        var this_tab = $(this);
        var group_class = this_tab.attr("data-group");
        var index = $(".tab").removeClass("current").index(this_tab);
        this_tab.addClass("current");
        var sections = $(".tabs-item."+group_class);
        var sections = sections.removeClass("current");
        $(sections[index]).addClass("current");
      });
    }
  };
});
