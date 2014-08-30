//#define NDEBUG //TODO uncomment to disable assertions - TODO define this value in makefile
#include <assert.h>
#include <string>
#include "Base64.h"

using namespace std;

const char Base64::intToBase64CharArray[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
								'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
								'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/'};

void Base64::append4Base64CharsFrom3Bytes(string *base64String, char *bytes, unsigned int length) {
	assert(length > 0 && length < 4);
	unsigned int data = 0;
	char c;
	for(int i = 0; i < length; i++) {
		c = bytes[i];
		data |= c << ((2 - i) * 8);
	}
	char base64Char;
	unsigned int binaryVal;
	unsigned int numDataBytes = length + 1;
	for(int i = 0; i < 4; i++) {
		if(i < numDataBytes) {
			binaryVal = (data >> ((3 - i) * 6)) & 0x3F;
			base64Char = intToBase64CharArray[binaryVal];
		} else {
			base64Char = '=';
		}
		*base64String += base64Char;
	}
}

string* Base64::convertHexStringToBase64(const char *bytes, unsigned int length) {
	string* ret = new string();
	char triplet[3];
	int ctr = 0;
	for(int i = 0; i < length; i++) {
		triplet[ctr] = bytes[i];
		if(++ctr == 3) {
			append4Base64CharsFrom3Bytes(ret, triplet, 3);
			ctr = 0;
		}
	}
	if(ctr != 0) {
		append4Base64CharsFrom3Bytes(ret, triplet, ctr);
	}
	return ret;
}

string* Base64::convertHexStringToBase64(string *s) {
	return convertHexStringToBase64(s->c_str(), (unsigned int)s->length());
}
