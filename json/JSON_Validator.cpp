//
// Created by krist on 17.10.2020.
//

#include "JSON_Validator.h"
#include "Numb_Validator.h"

bool JSON_Validator::checkObject(string &jsonString) {
    if (jsonString[0] == '{') {
        jsonString.erase(0, 1);
    }
    checkWhiteSpace(jsonString);
    bool isEndOfObject = false;
    while (!isEndOfObject) {
        checkWhiteSpace(jsonString);
        checkString(jsonString);
        checkWhiteSpace(jsonString);
        if (jsonString[0] == ':') {
            jsonString.erase(0, 1);
        } else {
            throw InvalidJsonException("Invalid json object");
        }
        checkValue(jsonString);
        if (jsonString[0] == ','){
        } else {
            if (jsonString[0] == '}'){
                isEndOfObject = true;
            } else {
                throw InvalidJsonException("Invalid json object");
            }
        }
        jsonString.erase(0, 1);
    }
    return jsonString.length() == 0;
}

void JSON_Validator::checkString(string &jsonString) {
    int length = 0;
    char currentChar = jsonString[length];
    if (jsonString[length] == '"') {
        length++;
        currentChar = jsonString[length];
    }
    //TODO add proccess /
    while (currentChar != '"') {
        length++;
        currentChar = jsonString[length];
    }
    if (jsonString[length] == '"') {
        length++;
    }
    jsonString.erase(0, length);
}

void JSON_Validator::checkArray(string &jsonString) {
    if (jsonString[0] == '[') {
        jsonString.erase(0, 1);
    }
    checkWhiteSpace(jsonString);
    bool isEndOfArray = false;
    while (!isEndOfArray) {
        checkValue(jsonString);
        if (jsonString[0] == ','){
        } else {
            if (jsonString[0] == ']'){
                isEndOfArray = true;
            } else {
                throw InvalidJsonException("Invalid json array");
            }
        }
        jsonString.erase(0, 1);
    }
}

void JSON_Validator::checkNumber(string &jsonNumber) {
    Numb_Validator numberValidator;
    numberValidator.isValidNumber(jsonNumber);
}

void JSON_Validator::checkTrue(string &jsonTrue) {
    if (jsonTrue[0] != 't' ||
        jsonTrue[1] != 'r' ||
        jsonTrue[2] != 'u' ||
        jsonTrue[3] != 'e') {
        throw InvalidJsonException("Invalid true token");
    }
    jsonTrue.erase(0, 4);
}

void JSON_Validator::checkFalse(string &jsonFalse) {
    if (jsonFalse[0] != 'f' ||
        jsonFalse[1] != 'a' ||
        jsonFalse[2] != 'l' ||
        jsonFalse[3] != 's' ||
        jsonFalse[4] != 'e') {
        throw InvalidJsonException("Invalid false token");
    }
    jsonFalse.erase(0, 5);
}

void JSON_Validator::checkNull(string &jsonString) {
    if (jsonString[0] != 'n' ||
        jsonString[1] != 'u' ||
        jsonString[2] != 'l' ||
        jsonString[3] != 'l') {
        throw InvalidJsonException("Invalid null token");
    }
    jsonString.erase(0, 4);
}

void JSON_Validator::checkWhiteSpace(string &jsonString) {
    int length = 0;
    char currentChar = jsonString[length];
    while (isWhiteSpace(currentChar)) {
        length++;
        currentChar = jsonString[length];
        //TODO использовать ексепшен
    }
    jsonString.erase(0, length);
}

void JSON_Validator::checkValue(string &jsonString) {
    checkWhiteSpace(jsonString);
    char currentChar = jsonString[0];
    switch (currentChar) {
        case '"':
            checkString(jsonString);
            break;
        case '{':
            checkObject(jsonString);
            break;
        case '[':
            checkArray(jsonString);
            break;
        case 't':
            checkTrue(jsonString);
            break;
        case 'f':
            checkFalse(jsonString);
            break;
        case 'n':
            checkNull(jsonString);
            break;
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        case '-':
            checkNumber(jsonString);
            break;
        default:
            throw InvalidJsonException("Invalid json value");
    }
    checkWhiteSpace(jsonString);
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