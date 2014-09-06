#include <iostream> //TODO remove
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <cmath>
#include "CharFrequency.h"

using namespace std;

float CharFrequency::commonFrequencyPercentList[] = {0.0812, 0.0149, 0.0271, 0.0432, 0.1202, 0.0230, 0.0203, 0.0592, 0.0731, 0.0010, 0.0069, 0.0398, 0.0261, 0.0695, 0.0768, 0.0182, 0.0011, 0.0602, 0.0628, 0.0910, 0.0288, 0.0111, 0.0209, 0.0017, 0.0211, 0.0007};

float CharFrequency::calculateDistanceFromCommonFrequency(string *s) {
	float frequencyTable[26];
	memset(&frequencyTable, 0, 26);
	int sLength = s->length();
	cout << "sLength:" << sLength << endl;
	char c;
	const char *sChars = s->c_str();
	for(int i = 0; i < sLength; i++) {
		c = sChars[i];
		c = tolower(c);
		unsigned char index = c - 'a';
		//frequencyTable[c - 'a']++;
		frequencyTable[index] = frequencyTable[index] + 1;
	}
	float ret = 0;
	float tmp;
	for(int i = 0; i < 26; i++) {
		tmp = frequencyTable[i];
		tmp /= sLength;
		ret += abs(tmp - commonFrequencyPercentList[i]);
	}
	return ret;
}
