$( document ).ready(function() {
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




  /* Modal windows */
  // $(".modal").each(function() {
  //   console.log("modal__");
  //   var link = $(this);
  //   var dialog = $("<div></div>")
  //     .load(link.attr("href"))
  //     .dialog({
  //       autoOpen: false,
  //       title: link.attr("title"),
  //       width: 500,
  //       height: 300
  //     });
  //   link.click(function() {
  //     dialog.dialog("open");
  //     return false;
  //   });
  // });

  /* This hack is to display correctly l2 menu items pointing to section tags */
  $(".toctree-l2").click(function() {
    $(".toctree-l2").removeClass("current");
    $(this).addClass("current");
  });
});
