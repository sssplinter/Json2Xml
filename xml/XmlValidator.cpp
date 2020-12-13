//
// Created by krist on 18.10.2020.
//

#include "XmlValidator.h"
#include <iostream>         //todo

void XmlValidator::checkProlog(string &xmlStr) {
//    int length = 0;
//    if(xmlStr[0] == '<' && xmlStr[1] == '?') {
//
//    }
}

void XmlValidator::checkAttribute(string &check_str) {

}

void XmlValidator::checkElement(string &check_str) {
    checkValue(check_str);
    if (!xm_stack.empty() && compare_tags(check_str)) {
        take_tag(check_str);
        xm_stack.pop();
    } else {
        string tag = take_tag(check_str);
        cout << tag << endl;
        xm_stack.push(tag);
        if (compare_tags(check_str)) {
            take_tag(check_str);
            xm_stack.pop();
        }
    }

}


void XmlValidator::checkValue(string &check_str) {
    while (check_str[0] != '<') {
        check_str.erase(0, 1);
    }
}

bool XmlValidator::checkXML(string xmlStr) {

    while (xmlStr != "") {
        checkElement(xmlStr);
    }
    return xm_stack.empty();
}

string XmlValidator::take_tag(string &check_str) {
    while (check_str[0] == ' ') {
        check_str.erase(0, 1);
    }
    if (check_str[0] == '<') {
        check_str.erase(0, 1);
    }
    string tag;
    while (check_str[0] != '>') {
        tag += check_str[0];
        check_str.erase(0, 1);
    }
    check_str.erase(0, 1);
    return tag;
}

bool XmlValidator::compare_tags(string check_str) {
    if (check_str[0] == '<') {
        check_str.erase(0, 1);
    }
    string tag;
    while (check_str[0] != '>') {
        tag += check_str[0];
        check_str.erase(0, 1);
    }
    tag.erase(0, 1);
    check_str.erase(0, 1);
    string temp = xm_stack.top();
    return tag == xm_stack.top();
}

// если первый символ - отк тег, тогда вызываем checEl  иначе ситывваем строчки пока не дойдем до закр тега (этого же)
// checEl считывает тег и вызывает chreckV
// checV смотр т если первый символ не откр тег то просто считываем до закр тега