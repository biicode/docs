#include "openssl/sha.h"
#include <string.h>
#include <stdio.h>

int main(){
	// The data to be hashed
	const unsigned char data[] = "Hello, world!";
	size_t length = sizeof(data);

	unsigned char hash[SHA_DIGEST_LENGTH];
	SHA1(data, length, hash);


	char mdString[SHA_DIGEST_LENGTH];
	 
	for(int i = 0; i < (SHA_DIGEST_LENGTH/2) - 1; i++)
           sprintf(&mdString[i*2], "%02x", (unsigned int)hash[i]);
 
    	printf("sha1 digest: %s\n", mdString);


	return 0;
}
