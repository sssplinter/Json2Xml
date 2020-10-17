//
// Created by krist on 17.10.2020.
//

#include "JSON_Validator.h"

bool JSON_Validator::checkObject(string json) {}

void JSON_Validator::checkString(string jsonString) {}

void JSON_Validator::checkArray(string jsonString) {}

void JSON_Validator::checkNumber(string jsonNumber) {
    
}

void JSON_Validator::checkTrue(string jsonTrue) {
    if(jsonTrue[0] != 't' ||
        jsonTrue[1] != 'r' ||
        jsonTrue[2] != 'u' ||
        jsonTrue[3] != 'e'){
        throw InvalidJsonException("Invalid true token");
    }
}

void JSON_Validator::checkFalse(string jsonFalse) {
    if (jsonFalse[0] != 'f' ||
        jsonFalse[1] != 'a' ||
        jsonFalse[2] != 'l' ||
        jsonFalse[3] != 's' ||
        jsonFalse[4] != 'e') {
        throw InvalidJsonException("Invalid false token");
    }
}

void JSON_Validator::checkNull(string jsonNull) {
    if (jsonNull[0] != 'n' ||
        jsonNull[1] != 'u' ||
        jsonNull[2] != 'l' ||
        jsonNull[3] != 'l') {
        throw InvalidJsonException("Invalid null token");
    }
}

void JSON_Validator::checkWhiteSpace(string jsonWhiteSpace) {
    int length = 0;
    char currentChar = jsonWhiteSpace[length];
    while (isWhiteSpace(currentChar)) {
        length++;
        currentChar = jsonWhiteSpace[length];
        //TODO использовать ексепшен
    }
    jsonWhiteSpace.erase(0, length);
}

bool isWhiteSpace(char currentChar) {
    switch (currentChar) {
        case ' ':
        case '\n':
        case '\t':
        case '\r':
            return true;
        default:
            return false;
    }
}