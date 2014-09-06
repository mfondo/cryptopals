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
	for(char c = CHAR_MIN; c <= CHAR_MAX; c++) {	
		Xor::xorBytes(encryptedBytes, c, decryptedBytes, encryptedBytesLength);
		//decryptedStr = Hex::convertBytesToHexString(decryptedBytes, encryptedBytesLength, false);TODO
		decryptedStr = new string(decryptedBytes, encryptedBytesLength);
		cout << "Decrypted Length:" << decryptedStr->length() << endl;
		//cout << "Decrypted:" << *decryptedStr << endl;TODO
		frequencyDistance = CharFrequency::calculateDistanceFromCommonFrequency(decryptedStr);
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
	cout << "Hex Test Success" << endl;//TODO wrong
}
