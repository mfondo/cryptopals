#include <iostream>
#include "CharFrequency.h"
#include <cmath>

void assertWordLength(float expected, float actual, float tolerance) {
	if(abs(expected - actual) > tolerance) {
		cout << "Fail average expected:" << expected << ":actual:" << actual << endl;
		exit(1);
	}
}

int main(int argc, char** argv) {
	string test = string("abcde");
	float distance = CharFrequency::calculateDistanceFromCommonFrequency(&test);
	cout << "distance:" << distance << endl;
	
	float avgWordLength = CharFrequency::calculateAverageWordLength(&test);
	assertWordLength(5, avgWordLength, 0.1f);
	string test2 = string("abc bd");
	avgWordLength = CharFrequency::calculateAverageWordLength(&test2);
	assertWordLength(2.5f, avgWordLength, 0.1f);
	string test3 = string(" abc bdef d ");
	avgWordLength = CharFrequency::calculateAverageWordLength(&test3);
	assertWordLength(2.67f, avgWordLength, 0.1f);
	
	cout << "Char Frequency Test Success" << endl;//TODO test distance near correct float value
}
