#ifndef XOR_H
#define XOR_H

class Xor {

	public:
		static void xorBytes(char *bytes1, char *bytes2, char *targetBytes, unsigned int bytesLength);
		static void xorBytes(char *bytes, char byte, char *targetBytes, unsigned int bytesLength);
};

#endif
