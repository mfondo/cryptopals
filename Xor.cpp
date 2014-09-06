#include "Xor.h"

void Xor::xorBytes(char *bytes1, char *bytes2, char *targetBytes, unsigned int bytesLength) {
	for(unsigned int i = 0; i < bytesLength; i++) {
		targetBytes[i] = bytes1[i] ^ bytes2[i];
	}
}

void Xor::xorBytes(char *bytes, char byte, char *targetBytes, unsigned int bytesLength) {
	for(unsigned int i = 0; i < bytesLength; i++) {
		targetBytes[i] = bytes[i] ^ byte;
	}
}