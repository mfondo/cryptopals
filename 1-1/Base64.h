#ifndef BASE64_H
#define BASE64_H

#include <string>

using namespace std;

class Base64 {

	private:
		static const char intToBase64CharArray[];
		
		static void append4Base64CharsFrom3Bytes(string *base64String, char *bytes, unsigned int length);

	public:
		static string* convertHexStringToBase64(const char *bytes, unsigned int length);
		static string* convertHexStringToBase64(string *s);

};

#endif
