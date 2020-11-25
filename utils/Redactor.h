//
// Created by krist on 16.11.2020.
//

#ifndef XML_TO_JSON_REDACTOR_H
#define XML_TO_JSON_REDACTOR_H

#include <string>
using namespace std;

class Redactor {
private:
    string editedText;
    string plainText;
    string compressedText;
//    int tabSize;

    static bool isWhiteSpaceChar(char plainChar);
    void calculateCompressedText();
    void calculateEditedText();

public:
    Redactor(string text);
    string getCompressedText();
    string getEditedText();
};


#endif //XML_TO_JSON_REDACTOR_H
