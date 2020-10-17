#include <iostream>
#include <string>

#include "json/Numb_Validator.h"

using namespace std;

bool isValid(string number);

int main() {
    string str = "1213.432E+";
    cout<<isValid(str);
    return 0;
}

bool isValid(string number) {
    Numb_Validator validator;
    return validator.isValidNumber(number);
}