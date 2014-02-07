#pragma once

#include "lasote/httpserver/http_middleware.h"

using namespace httpserver;

class MyHttpMiddleware : public httpserver::HttpMiddleware {
	public:
		MyHttpMiddleware() : HttpMiddleware(NULL){}
		MyHttpMiddleware(HttpMiddleware* other_middleware) : HttpMiddleware(other_middleware){
		}
		virtual ~MyHttpMiddleware();
		virtual void call(Request&, Response&);
};