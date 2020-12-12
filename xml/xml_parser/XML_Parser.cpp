#include "XML_Parser.h"

map<string, XmlObject> XML_Parser::parse(string &xml_str) {
    source = xml_str;
    position = 0;
    return parseElement();
}

map<string, XmlObject> XML_Parser::parseElement() {
    map<string, XmlObject> value;
    string elementName = "";
    position++;
    while (source[position] != '<' && source[position] != ' ') {
        elementName += source[position];
        position++;
    }
    map<string, XmlValue> attributes = parseAttributes();
    position++; // >
    xml
    return map<string, XmlObject>();
}

map<string, XmlValue> XML_Parser::parseAttributes() {
    return map<string, XmlValue>();
}

XmlValue XML_Parser::parseValue() {
    return
}
