#include <iostream>
#include <climits>
#include <cfloat>
#include "Hex.h"
#include "Xor.h"
#include "CharFrequency.h"

int main(int argc, char** argv) {
	string encrypted = string("1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736");
	char *encryptedBytes;
	unsigned int encryptedBytesLength;
	Hex::convertHexStringToBytes(&encrypted, &encryptedBytes, &encryptedBytesLength);
	
	char *decryptedBytes = (char *)malloc(encryptedBytesLength);
	string *decryptedStr;
	float minFrequencyDistance = FLT_MAX;
	string *minFrequencyDistanceStr = NULL;
	float frequencyDistance;
	for(char c = CHAR_MIN; c < CHAR_MAX; c++) {	
		Xor::xorBytes(encryptedBytes, c, decryptedBytes, encryptedBytesLength);
		decryptedStr = new string(decryptedBytes, encryptedBytesLength);
		frequencyDistance = CharFrequency::calculateDistanceFromCommonFrequency(decryptedStr);
		cout << "Distance:" << frequencyDistance << "str:" << *decryptedStr << endl;
		if(frequencyDistance < minFrequencyDistance) {
			if(minFrequencyDistanceStr != NULL) {
				delete minFrequencyDistanceStr;
			}
			minFrequencyDistanceStr = decryptedStr;
			minFrequencyDistance = frequencyDistance;
		} else {
			delete decryptedStr;
		}		
	}
	cout << "Min Frequency Distance:" << minFrequencyDistance << ":" << *minFrequencyDistanceStr << endl;
	free(decryptedBytes);	
	cout << "Challenge 1-3 Success" << endl;//TODO wrong
}
