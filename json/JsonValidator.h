//
// Created by krist on 17.10.2020.
//

#ifndef XML_TO_JSON_JSONVALIDATOR_H
#define XML_TO_JSON_JSONVALIDATOR_H

#include <string>
#include "InvalidJsonException.h"

using namespace std;
class JsonValidator {
public:
    bool checkObject(string &json);
    void checkValue(string &jsonValue);
    void checkArray(string &jsonString);
    void checkString(string &jsonString);
    void checkNumber(string &jsonNumber);
    void checkTrue(string &jsonTrue);
    void checkFalse(string &jsonFalse);
    void checkNull(string &jsonNull);
private:
    void checkWhiteSpace(string &jsonWhiteSpace);
};

bool isWhiteSpace(char currentChar);


#endif //XML_TO_JSON_JSONVALIDATOR_H
