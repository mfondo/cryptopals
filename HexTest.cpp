#include <iostream>
#include "Hex.h"

void testConvert(string *hexString, char *expectedBytes, unsigned int expectedBytesLength) {
	char *actualBytes;
	unsigned int actualBytesLength;
	Hex::convertHexStringToBytes(hexString, &actualBytes, &actualBytesLength);
	if(expectedBytesLength != actualBytesLength) {
		cout << "Expected length:" << expectedBytesLength << ":Actual length:" << actualBytesLength << endl;
		exit(1);
	}
	char expectedByte;
	char actualByte;
	for(int i = 0; i < expectedBytesLength; i++) {
		expectedByte = expectedBytes[i];
		actualByte = actualBytes[i];
		if(expectedByte != actualByte) {
			cout << "Expected byte:" << expectedByte << ":Actual byte:" << actualByte << endl;
			exit(1);
		}
	}	
	free(actualBytes);
}

void testStringsEqual(string *expectedStr, string *actualStr) {
	if(*expectedStr != *actualStr) {
		cout << "Expected string:" << *expectedStr << ":Actual string:" << *actualStr << endl;
		exit(1);
	}
}

int main(int argc, char** argv) {
	string s1 = string("f");
	string s2 = string("FF");
	string s3 = string("8D7");
	string s4 = string("97D7");

	char expectedBytes1[1] = {15};
	testConvert(&s1, expectedBytes1, 1);
	char expectedBytes2[1] = {255};
	testConvert(&s2, expectedBytes2, 1);
	char expectedBytes3[2] = {8, 215};
	testConvert(&s3, expectedBytes3, 2);
	char expectedBytes4[2] = {151, 215};
	testConvert(&s4, expectedBytes4, 2);
	
	string *actualStr = Hex::convertBytesToHexString(expectedBytes1, 1, false);
	testStringsEqual(&s1, actualStr);	
	actualStr = Hex::convertBytesToHexString(expectedBytes2, 1, true);
	testStringsEqual(&s2, actualStr);	
	actualStr = Hex::convertBytesToHexString(expectedBytes3, 2, true);
	testStringsEqual(&s3, actualStr);
	actualStr = Hex::convertBytesToHexString(expectedBytes4, 2, true);
	testStringsEqual(&s4, actualStr);
	
	cout << "Hex Test Success" << endl;
}
