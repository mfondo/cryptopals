#include <iostream>
#include "CharFrequency.h"

int main(int argc, char** argv) {
	string test = string("abcde");
	float distance = CharFrequency::calculateDistanceFromCommonFrequency(&test);
	cout << "distance:" << distance << endl;
	cout << "Char Frequency Test Success" << endl;//TODO test distance near correct float value
}
