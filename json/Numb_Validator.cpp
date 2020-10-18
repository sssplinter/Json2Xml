//
// Created by krist on 17.10.2020.
//

#include "Numb_Validator.h"
#include "InvalidJsonNumberException.h"

bool isDigit(char currentChar, bool withZero);

void Numb_Validator::checkMinus(string &numberStr) {
    if (numberStr[0] == '-') {
        numberStr.erase(0, 1);
    }
}

void Numb_Validator::checkZero(string &numberStr) {
    if (numberStr[0] == '0') {
        numberStr.erase(0, 1);
    }
}

void Numb_Validator::checkDigits(string &numberStr) {
    int length = 0;
    char currentChar = numberStr[length];
    checkMinus(numberStr);
    while (isDigit(currentChar, length != 0)) {
        length++;
        currentChar = numberStr[length];
    }
    numberStr.erase(0, length);
}

bool isDigit(char currentChar, bool withZero) {
    if (withZero) {
        return currentChar >= '0' && currentChar <= '9';
    } else {
        return currentChar >= '1' && currentChar <= '9';
    }
}

void Numb_Validator::checkFraction(string &numberStr) {
    int length = 0;
    char currentChar = numberStr[length];
    if (currentChar == '.') {
        length++;
        currentChar = numberStr[length];
        if (currentChar == '-' || currentChar == '+') {
            length++;
            currentChar = numberStr[length];
        }
        if (isDigit(currentChar, true)) {
            length++;
            currentChar = numberStr[length];

        } else {
            throw InvalidJsonNumberException("Invalid fraction");
        }
        while (isDigit(currentChar, true)) {
            length++;
            currentChar = numberStr[length];
        }
        numberStr.erase(0, length);
    }

}

void Numb_Validator::checkExponent(string &numberStr) {
    int length = 0;
    char currentChar = numberStr[length];
    if (currentChar == 'e' || currentChar == 'E') {
        length++;
        currentChar = numberStr[length];
        if (currentChar == '+' || currentChar == '-') {
            length++;
            currentChar = numberStr[length];
        }
        if (isDigit(currentChar, true)) {
            length++;
            currentChar = numberStr[length];
        } else {
            throw InvalidJsonNumberException("Invalid exponent");
        }
        while (isDigit(currentChar, true)) {
            length++;
            currentChar = numberStr[length];
        }
        numberStr.erase(0, length);
    }

}

bool Numb_Validator::isValidNumber(string &numberStr) {
    checkMinus(numberStr);
    if (numberStr[0] == '0') {
        checkZero(numberStr);
    } else {
        checkDigits(numberStr);
    }
    checkFraction(numberStr);
    checkExponent(numberStr);
    return numberStr.length() == 0;
}
