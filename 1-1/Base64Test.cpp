#include <iostream>
#include "Base64.h"

void testHexToBase64(string *toEncode, string *expectedBase64) {
	string* base64 = Base64::convertHexStringToBase64(toEncode);
	if(*expectedBase64 != *base64) {
		cout << "Expected:" << *expectedBase64 << ":Actual:" << *base64 << endl;
		exit(1);
	}
	delete toEncode;
	delete expectedBase64;
	delete base64;
}

int main(int argc, char** argv) {
	testHexToBase64(new string("Man"), new string("TWFu"));
	testHexToBase64(new string("Ma"), new string("TWE="));
	testHexToBase64(new string("M"), new string("TQ=="));
	testHexToBase64(new string("a"), new string("YQ=="));
	testHexToBase64(new string("ab"), new string("YWI="));
	testHexToBase64(new string("abc"), new string("YWJj"));
	testHexToBase64(new string("abcd"), new string("YWJjZA=="));
	testHexToBase64(new string("abcde"), new string("YWJjZGU="));
	testHexToBase64(new string("abcdef"), new string("YWJjZGVm"));
	
	//the actual challenge string
	//TODO need to use the char* function - and convert the strings to bytes directly)
	testHexToBase64(new string("49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d"), new string("SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t"));
}
