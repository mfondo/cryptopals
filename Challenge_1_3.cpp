#include <iostream>
#include <climits>
#include <cfloat>
#include "Hex.h"
#include "Xor.h"
#include <map>
#include "CharFrequency.h"

struct FloatCompare {
	bool operator()(const float& a, const float& b) const {
		return a < b;
	}
};

int main(int argc, char** argv) {
	string encrypted = string("1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736");
	char *encryptedBytes;
	unsigned int encryptedBytesLength;
	Hex::convertHexStringToBytes(&encrypted, &encryptedBytes, &encryptedBytesLength);
	
	char *decryptedBytes = (char *)malloc(encryptedBytesLength);
	string *decryptedStr;
	float frequencyDistance;
	const int maxMapSize = 10;//adjust as necessary if top maxMapSize results does not contain correct decrypted string
	std::multimap<float, string*, FloatCompare> orderedFrequencyDistanceMap;
	std::multimap<float, string*>::iterator iter;
	for(char c = CHAR_MIN; c < CHAR_MAX; c++) {	
		Xor::xorBytes(encryptedBytes, c, decryptedBytes, encryptedBytesLength);
		decryptedStr = new string(decryptedBytes, encryptedBytesLength);
		frequencyDistance = CharFrequency::calculateDistanceFromCommonFrequency(decryptedStr);
		orderedFrequencyDistanceMap.insert(std::pair<float, string*>(frequencyDistance, decryptedStr));
		if(orderedFrequencyDistanceMap.size() > maxMapSize) {
			iter = orderedFrequencyDistanceMap.end();
			iter--;
			delete (*iter).second;
			orderedFrequencyDistanceMap.erase(iter);
		}
	}
	for(iter = orderedFrequencyDistanceMap.begin(); iter != orderedFrequencyDistanceMap.end(); iter++) {
		cout << "key:" << (*iter).first << ":val:" << *((*iter).second) << endl;
	}
	free(decryptedBytes);	
	cout << "Challenge 1-3 Success" << endl;
}
