#include "sha.h"
#include "filters.h"
#include "hex.h"
#include <iostream>
#include <string>

int main() {
	CryptoPP::SHA1 sha1;
	std::string source = "Hello";  //This will be randomly generated somehow
	std::string hash = "";
	CryptoPP::StringSource(source, true, new CryptoPP::HashFilter(sha1, new CryptoPP::HexEncoder(new CryptoPP::StringSink(hash))));
	std::cout << hash;
}