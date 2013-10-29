Crypto++, a free C++ class library of cryptographic schemes
===========================================================

Crypto++ is a C++ class library of cryptographic algorithms and schemes written by Wei Dai. For more information about this library, visit their `official website <http://www.cryptopp.com/>`_ or wiki.

You can find the biicode library site following this link.

This first basic example shows hot to encrypt a message with SHA1 code.::

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