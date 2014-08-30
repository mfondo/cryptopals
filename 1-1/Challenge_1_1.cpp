#include <iostream>
#include "Base64.h"
#include "Hex.h"

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
	string hexToEncode = string("49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d");	
	char* bytes;
	unsigned int bytesLength;
	Hex::convertHexStringToBytes(&hexToEncode, &bytes, &bytesLength);
	string* actualBase64 = Base64::convertHexStringToBase64(bytes, bytesLength);	
	
	string expectedBase64 = string("SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t");
	if(expectedBase64 != *actualBase64) {
		cout << "Expected:" << expectedBase64 << ":Actual:" << *actualBase64 << endl;
		exit(1);
	}
	cout << "Success" << endl;	
}
