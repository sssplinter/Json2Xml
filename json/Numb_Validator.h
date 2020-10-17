//
// Created by krist on 17.10.2020.
//

#ifndef XML_TO_JSON_NUMB_VALIDATOR_H
#define XML_TO_JSON_NUMB_VALIDATOR_H

#include <string>

using namespace std;
class Numb_Validator {
public:
    bool isValidNumber(string numberStr);
private:
    void checkMinus(string &numberStr);
    void checkZero(string &numberStr);
    void checkDigits(string &numberStr);
    void checkFraction(string &numberStr);
    void checkExponent(string &numberStr);
};


#endif //XML_TO_JSON_NUMB_VALIDATOR_H
