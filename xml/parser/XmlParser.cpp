#include "XmlParser.h"

XmlElement *XmlParser::parse(string &str) {
    source = comp(str);
    position = 0;
    position += 6; // <root>
    XmlElement *xmlElement = parseElement();
    position += 7; // </root>
    return xmlElement;
}

XmlElement *XmlParser::parseElement() {
    XmlElement *element = new XmlElement();
    while (source[position + 1] != '/') {
        string elementName = "";
        position++;
        while (source[position] != '>' && source[position] != ' ') {
            elementName += source[position];
            position++;
        }
        map<string, XmlValue> attributes = parseAttributes();
        position++; // >

        XmlObject *xmlObject;
        if (source[position] == '<') {
            xmlObject = parseElement();
        } else {
            xmlObject = parseValue();
        }

        element->addObject(elementName, xmlObject);

        position++; // <
        position++;

        for (int i = 0; i < elementName.size(); i++) {
            position++;
        }
        position++; // >
    }
    return element;
}

map<string, XmlValue> XmlParser::parseAttributes() {
    return map<string, XmlValue>();
}

XmlValue *XmlParser::parseValue() {

    string xmlValue = "";
    while (source[position] != '<') {
        xmlValue += source[position];
        position++;
    }

    return new XmlValue(xmlValue);
}

string XmlParser::comp(string source) {
    string initialString = "";
    bool isString = false;
    int l = source.length();
    char currentChar;
    for (int i = 0; i < l; i++) {
        currentChar = source[i];
        if (currentChar == '"') {
            isString = !isString;
        }
        if ((!isString && !isWhiteSpace(currentChar)) || isString) {
            initialString += currentChar;
        }
    }
    return initialString; // строка или нестрока и пустое пространство
}

bool XmlParser::isWhiteSpace(char currentChar) {
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
