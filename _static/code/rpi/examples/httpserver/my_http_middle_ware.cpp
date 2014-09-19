#include "my_http_middle_ware.h"
#include "lasote/httpserver/exception.h"
#include "lasote/httpserver/model/method.h"
#include "sstream"
#include "iostream"

namespace httpserver {

    MyHttpMiddleware::~MyHttpMiddleware(){

    }
    	
    void  MyHttpMiddleware::call(Request&  request,  Response&  response){
    	ostringstream  html;
        string checkedOn = "", checkedOff = "";

    	html  <<  "<!DOCTYPE html>\n<html>\n<body>\n";

    	if(request.get("mode") == "on"){ myLed.on(); checkedOn = "checked";}
    	if(request.get("mode") == "off"){ myLed.off(); checkedOff = "checked";}
    		
    	//Build the html form
    	string  form;
    	form  =  "\
    				<form name='formulary' action='/hello' method='POST'>\n\
    						Led Mode (on/off): <br>\n\
    					<input type='radio' name='mode' value='on' " + checkedOn + "> On<br>\n\
    					<input type='radio' name='mode' value='off' " + checkedOff + "> Off<br>\n\
    					<input type='submit''/>\n\
    				</form>\n\
    				";

    	html  <<  form  <<  "</body>\n</html>\n";

    	// Set content type we are printing
    	response.content_type("text/html");
    	// Set the body
    	response.body  =  html.str();
    }



} /* namespace httpserver */