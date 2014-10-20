#include "hithwen/lwan/common/lwan.h"

lwan_http_status_t
hello_world(lwan_request_t *request,
            lwan_response_t *response,
            void *data __attribute__((unused)))
{
    static lwan_key_value_t headers[] = {
        { .key = "X-The-Answer-To-The-Universal-Question", .value = "42" },
        { NULL, NULL }
    };
    response->headers = headers;
    response->mime_type = "text/plain";

    const char *name = lwan_request_get_query_param(request, "name");
    if (name)
        strbuf_printf(response->buffer, "Hello, %s!", name);
    else
        strbuf_set_static(response->buffer, "Hello, world!", sizeof("Hello, world!") -1);

    return HTTP_OK;
}

int
main(void)
{
    lwan_t l;

    lwan_init(&l);
    lwan_main_loop(&l);
    lwan_shutdown(&l);

    return 0;
}
