#ifndef HEX_H
#define HEX_H

#include <string>

using namespace std;

class Hex {

	private:
		static char convertHexCharToByte(char hexChar);

	public:
		static void convertHexStringToBytes(string *hexString, char **bytes, unsigned int *bytesLength);

};

#endif
