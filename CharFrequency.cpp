#include <string>
#include <stdio.h>
#include <ctype.h>
#include <cmath>
#include "CharFrequency.h"

using namespace std;

float CharFrequency::commonFrequencyPercentList[] = {0.0812, 0.0149, 0.0271, 0.0432, 0.1202, 0.0230, 0.0203, 0.0592, 0.0731, 0.0010, 0.0069, 0.0398, 0.0261, 0.0695, 0.0768, 0.0182, 0.0011, 0.0602, 0.0628, 0.0910, 0.0288, 0.0111, 0.0209, 0.0017, 0.0211, 0.0007};

float CharFrequency::calculateDistanceFromCommonFrequency(string *s) {
	return calculateDistanceFromCommonFrequency(s, 0.1f);
}

float CharFrequency::calculateDistanceFromCommonFrequency(string *s, float invalidCharPenalty) {
	float frequencyTable[26];
	memset(&frequencyTable, 0, 26 * sizeof(float));
	int sLength = s->length();
	char c;
	const char *sChars = s->c_str();
	unsigned char index;
	float ret = 0;
	for(int i = 0; i < sLength; i++) {
		c = sChars[i];
		c = tolower(c);
		if(c >= 'a' && c <= 'z') {//ignore non letter characters
			index = c - 'a';
			frequencyTable[index] = frequencyTable[index] + 1;
		} else if (c < '0' && c > '9'){
			ret += invalidCharPenalty;
		}
	}
	float tmp;
	for(int i = 0; i < 26; i++) {
		tmp = frequencyTable[i];
		tmp /= sLength;
		ret += abs(tmp - commonFrequencyPercentList[i]);
	}
	return ret;
}

//TODO doing a histogram of word length would be even better
float CharFrequency::calculateAverageWordLength(string *s) {
	unsigned int wordLengthTotal = 0;
	unsigned int wordCnt = 0;
	bool startCounting = false;
	unsigned int currentWordCnt = 0;
	const char *sChars = s->c_str();
	char c;
	for(int i = 0; i < s->length(); i++) {
		c = sChars[i];
		if(c == ' ' || c == '\t' || c == '\n' || c == '\r') {
			if(currentWordCnt > 0) {
				wordLengthTotal += currentWordCnt;
				wordCnt++;
				currentWordCnt = 0;
			}
			startCounting = false;
		} else {
			if(!startCounting) {
				startCounting = true;				
			}
			currentWordCnt++;
		}
	}
	if(currentWordCnt > 0) {
		wordLengthTotal += currentWordCnt;
		wordCnt++;
	}
	return ((float)wordLengthTotal) / ((float)wordCnt);
}
