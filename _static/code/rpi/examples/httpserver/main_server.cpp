#include "lasote/httpserver/http_server.h"
#include "my_http_middle_ware.h"

using namespace httpserver;
using namespace gip;

int main(){
	MyHttpMiddleware my_mmiddleware;
	HttpServerConf conf(9000, 300, 60, 5);

	HttpServer http_server;

	http_server.run(&my_mmiddleware, &conf);

	return 0;

}