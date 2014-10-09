#include <cstdio>
#include <fstream>
#include <sstream>
#include <random>

#include <hithwen/miniutf/miniutf.hpp>
#include <hithwen/miniutf/miniutf_collation.hpp>


using namespace std;

void dump(const string & str) {
    for (size_t i = 0; i < str.length(); )
        printf(i ? "%04X" : " %04X", miniutf::utf8_decode(str, i));
}

int check_eq(const char *test, const string & expected, const string & got) {
    if (expected == got)
        return 1;

    printf("%s: expected \"", test);
    dump(expected);
    printf("\", got \"");
    dump(got);
    printf("\"\n");
    return 0;
}

string match_key_as_hex(const vector<uint32_t> & key) {
    string out;
    for (uint32_t c : key) {
        char outc[10];
        snprintf(outc, 10, "%08X ", (unsigned int)c);
        out.append(outc);
    }
    return out.substr(0,out.size()-1);
}

template <class T> string string_as_hex(const T & s) {
    string out;
    for (size_t i = 0; i < s.size(); i++) {
        char outc[10];
        snprintf(outc, 10, "%02X ", (unsigned int)s[i]);
        out.append(outc);
    }
    return out.substr(0,out.size()-1);
}

bool check_match_key(const string & s1, const string & s2) {
    vector<uint32_t> k1 = miniutf::match_key(s1);
    vector<uint32_t> k2 = miniutf::match_key(s2);
    if (k1 != k2) {
        printf("match_key(%s,%s) test failed\n", string_as_hex(s1).c_str(), string_as_hex(s2).c_str());
        printf("  got %s, expected %s\n", match_key_as_hex(k1).c_str(), match_key_as_hex(k2).c_str());
        return false;
    }
    return true;
}


int main(void) {

    string utf8_test = { '\x61', '\x00', '\xF0', '\x9F', '\x92', '\xA9' };
    u16string utf16_test = { 0x61, 0, 0xD83D, 0xDCA9 };

    // We also have some tests of UTF-8 to UTF-16 conversion
    string utf8 = miniutf::to_utf8(utf16_test);
    if (!check_eq("16-to-8", utf8_test, utf8))
        return 1;

    u16string utf16 = miniutf::to_utf16(utf8_test);
    if (utf16 != utf16_test) {
        printf("utf8-to-utf16 test failed: got ");
        for (size_t i = 0; i < utf16.length(); i++) printf("%04x ", (uint16_t)utf16[i]);
        printf("\n");
        return 1;
    }

    // Test match_key function
    if (!check_match_key(u8"Øǣç",
                         u8"oaec")) { return 1; }
    if (!check_match_key(u8"ãäåèéêëüõñ",
                         u8"aaaeeeeuon")) { return 1; }

    printf("OK\n");
    return 0;
}
