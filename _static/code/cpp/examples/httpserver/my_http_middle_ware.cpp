#include "lasote/my_block/my_http_middle_ware.h"
#include "sstream"
#include "iostream"


MyHttpMiddleware::~MyHttpMiddleware(){

}

void MyHttpMiddleware::call(Request& request, Response& response){
	ostringstream html;

	html << "<!DOCTYPE html>\n<html>\n<body>\n";

	if(request.get("name") != ""){
		html << "Hello " << request.get("name") << "<br><br>";
	}

	//Build the html form
	string form;
	form = "\
				<form name='form' action='/' method='POST'>\n\
					Name: <br>\n\
					<input type='text' name='name'> <br>\n\
					<input type='submit''/>\n\
				</form>\n\
			  ";

	html << form << "</body>\n</html>\n";

	// Set content type we are printing
	response.content_type("text/html");
	// Set the body
	response.body = html.str();
}