#ifndef CHAR_FREQUENCY_H
#define CHAR_FREQUENCY_H

#include <string>

using namespace std;

class CharFrequency {

	private:
		static float commonFrequencyPercentList[];	

	public:
		float static calculateDistanceFromCommonFrequency(string *s);
		float static calculateDistanceFromCommonFrequency(string *s, float invalidCharPenalty);		
		float static calculateAverageWordLength(string *s);
};

#endif
