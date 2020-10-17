//
// Created by krist on 17.10.2020.
//

#ifndef XML_TO_JSON_JSON_VALIDATOR_H
#define XML_TO_JSON_JSON_VALIDATOR_H

#include <string>
#include "InvalidJsonException.h"

using namespace std;
class JSON_Validator {
public:
    bool checkObject(string json);

private:
    void checkArray(string jsonString);
    void checkString(string jsonString);
    void checkNumber(string jsonNumber);
    void checkTrue(string jsonTrue);
    void checkFalse(string jsonFalse);
    void checkNull(string jsonNull);
    void checkWhiteSpace(string jsonWhiteSpace);
};

bool isWhiteSpace(char currentChar);


#endif //XML_TO_JSON_JSON_VALIDATOR_H
