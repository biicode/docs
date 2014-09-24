/**
 * Simple example to write to a file
 */
#include <melikyan/ptypes/include/pstreams.h>
#include <melikyan/ptypes/include/pport.h>

using namespace pt;

int main() {
        const char* fname = "stmtest.txt";
        outfile f(fname,false);
        f.set_bufsize(1024);  // the default value in this version is 8192
        try {
                f.open();
                f.put("This is a test file.\n");
                f.close();
        } catch (estream* e) {
                perr.putf(e->get_message());
                delete e;
        }
        return 0;
}
