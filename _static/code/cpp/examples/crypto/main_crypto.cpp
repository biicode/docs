#include "cryptopp/cryptopp/sha.h"
#include "cryptopp/cryptopp/filters.h"
#include "cryptopp/cryptopp/hex.h"
#include <iostream>
#include <string>

int main() {
	CryptoPP::SHA1 sha1;
	std::string source = "Hello";  //This will be randomly generated somehow
	std::string hash = "";
	CryptoPP::StringSource(source, true, new CryptoPP::HashFilter(sha1, new CryptoPP::HexEncoder(new CryptoPP::StringSink(hash))));
	std::cout << hash;
}
