#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Xor.h"
#include "Hex.h"

int main(int argc, char** argv) {
	string s1 = string("1c0111001f010100061a024b53535009181c");
	char *s1Bytes;
	unsigned int s1BytesLength;
	Hex::convertHexStringToBytes(&s1, &s1Bytes, &s1BytesLength);
	string s2 = string("686974207468652062756c6c277320657965");
	char *s2Bytes;
	unsigned int s2BytesLength;
	Hex::convertHexStringToBytes(&s2, &s2Bytes, &s2BytesLength);
	if(s1BytesLength != s2BytesLength) {
		cout << "Unexpected length" << s1BytesLength << "-" << s2BytesLength << endl;
		exit(1);
	}
	char s3Bytes[s1BytesLength];
	Xor::xorBytes(s1Bytes, s2Bytes, s3Bytes, s2BytesLength);
	string actualResult = string(s3Bytes, s1BytesLength);
	string expectedResult = string("746865206b696420646f6e277420706c6179");
	char *expectedResultBytes;
	unsigned int expectedResultBytesLength;
	Hex::convertHexStringToBytes(&expectedResult, &expectedResultBytes, &expectedResultBytesLength);
	if(memcmp(expectedResultBytes, &s3Bytes, (size_t)s1BytesLength) != 0) {
		cout << "Expected:" << expectedResult << ":Actual:" << actualResult << endl;
		exit(1);
	}
	cout << "Chalenge 1-2 Success" << endl;	
}
