#include <iostream>
#include "XmlPresenter.h"

string XmlPresenter::convertToString(XmlElement *xmlElement) {
    string result;
    bool wasRooted = this->rooted;
    if (!wasRooted) {
        offset = 0;
    }
    result += getOffset();
    result += "<root>\n";
    this->rooted = true;
    offset += 4;
    map<string, XmlObject *> *xmlObjects = xmlElement->getValue();
    for (auto iter = xmlObjects->begin(); iter != xmlObjects->end(); iter++) {
        string name = iter->first;
        result += getOffset();
        result += '<';
        result += name;
        result += ">\n";
        XmlObject *xmlObject = iter->second;
        if (XmlValue *xmlValue = dynamic_cast<XmlValue *>(xmlObject)) {
            result += convertToString(xmlValue);
        }
        if (XmlArray *xmlArray = dynamic_cast<XmlArray *>(xmlObject)) {
            result += convertToString(xmlArray);
        }
        if (XmlElement *xmlElement = dynamic_cast<XmlElement *>(xmlObject)) {
            result += convertToString(xmlElement);
        }
        result += getOffset();
        result += "</";
        result += name;
        result += ">\n";
    }

    offset -= 4;
    result += getOffset();
    result += "</root>\n";
    this->rooted = wasRooted;

    return result;
}

string XmlPresenter::convertToString(XmlArray *xmlArray) {
    string result;
    offset += 4;
    list<XmlObject *> *xmlObjects = xmlArray->getValue();
    for (auto iter = xmlObjects->begin(); iter != xmlObjects->end(); iter++) {
        XmlObject *xmlObject = *iter;
        if (XmlValue *xmlValue = dynamic_cast<XmlValue *>(xmlObject)) {
            result += convertToString(xmlValue);
        }
        if (XmlArray *xmlArray = dynamic_cast<XmlArray *>(xmlObject)) {
            result += convertToString(xmlArray);
        }
        if (XmlElement *xmlElement = dynamic_cast<XmlElement *>(xmlObject)) {
            result += convertToString(xmlElement);
        }
    }
    offset -= 4;
    return result;
}

string XmlPresenter::convertToString(XmlValue *xmlValue) {
    string result;
    offset += 4;
    result += getOffset();
    string value = xmlValue->getValue();
    result += value;
    result += '\n';
    offset -= 4;

    return result;
}

string XmlPresenter::getOffset() {
    string result;
    for (int i = 0; i < offset; i++) {
        result += ' ';
    }

    return result;
}
