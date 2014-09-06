#ifndef CHAR_FREQUENCY_H
#define CHAR_FREQUENCY_H

#include <string>

using namespace std;

class CharFrequency {

	private:
		static float commonFrequencyPercentList[];	

	public:
		float static calculateDistanceFromCommonFrequency(string *s);
};

#endif
