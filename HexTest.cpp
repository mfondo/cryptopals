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
	delete hexString;
	free(actualBytes);
}

int main(int argc, char** argv) {
	char expectedBytes1[1] = {15};
	testConvert(new string("f"), expectedBytes1, 1);
	char expectedBytes2[1] = {255};
	testConvert(new string("FF"), expectedBytes2, 1);
	char expectedBytes3[2] = {8, 215};
	testConvert(new string("8D7"), expectedBytes3, 2);
	char expectedBytes4[2] = {151, 215};
	testConvert(new string("97D7"), expectedBytes4, 2);
	cout << "Hex Test Success" << endl;
}
