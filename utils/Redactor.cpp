//
// Created by krist on 16.11.2020.
//
#pragma  hdrstop
#include "Redactor.h"
#include <utility> // ля работы с std::move - r-value, l-value https://habr.com/ru/post/348198/

Redactor::Redactor(string text) {
    this->plainText = std::move(text);// симантика перемещения, не коппирования
}

void Redactor::calculateCompressedText() {
    compressedText = "";
    bool isString = false;
    for (unsigned i = 0; i < plainText.length(); i++) {
        if ((plainText[i] == '\"') && (plainText[i - 1] != '\\')) {
            isString = !isString;
        }
        if ((isString) || (!isWhiteSpaceChar(plainText[i]))) {
            compressedText = compressedText + plainText[i];
        }
    }
}

bool Redactor::isWhiteSpaceChar(char currentChar) {
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