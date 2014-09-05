#ifndef HEX_H
#define HEX_H

#include <string>

using namespace std;

class Hex {

	private:
		static char convertHexCharToByte(char hexChar);
		static char convertByteToHexChar(char hexChar, bool upperCaseChars);

	public:
		static void convertHexStringToBytes(string *hexString, char **bytes, unsigned int *bytesLength);
		static string * convertBytesToHexString(char *bytes, unsigned int bytesLength, bool upperCaseChars);
};

#endif
