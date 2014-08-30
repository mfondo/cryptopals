#include <string>
#include <stdexcept>
#include <stdlib.h>
#include "Hex.h"

using namespace std;

char Hex::convertHexCharToByte(char c) {
	char byte;
	if(c >= '0' && c <= '9') {
		byte = c - '0';
	} else if(c >= 'a' && c <= 'f') {
		byte = c - 'a' + 10;
	} else if(c >= 'A' && c <= 'F') {
		byte = c - 'A' + 10;
	} else {
		throw invalid_argument("Invalid hex character");
	}
	return byte;
}

void Hex::convertHexStringToBytes(string *hexString, char **bytes, unsigned int *bytesLength) {
	int hexStringLength = hexString->length();
	int tmpBytesLength;
	if(hexStringLength % 2 == 0) {
		tmpBytesLength = hexStringLength / 2;
	} else {
		tmpBytesLength = (hexStringLength + 1) / 2;
	}
	*bytesLength = tmpBytesLength;
	*bytes = (char *)malloc(tmpBytesLength);
	char cHighBits, cLowBits;
	char byte;
	for(int i = hexStringLength - 1; i >= 0; i -= 2) {
		cLowBits = hexString->at(i);
		if(i > 0) {
			cHighBits = hexString->at(i - 1);
		} else {
			cHighBits = '0';
		}
		cLowBits = convertHexCharToByte(cLowBits);
		cHighBits = convertHexCharToByte(cHighBits);
		byte = 0;
		byte |= cLowBits;
		byte |= (cHighBits << 4);
		(*bytes)[i / 2] = byte;
	}
}
