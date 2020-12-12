#include <string>
#include <map>
#include "xml_item/XmlObject.h"
#include "xml_item/XmlValue.h"
#include "xml_item/XmlElement.h"

#ifndef XML_TO_JSON_XML_PARSER_H
#define XML_TO_JSON_XML_PARSER_H

using namespace std;

class XML_Parser {
public:
    XmlElement* parse(string &xml_str);
private:

    string source = "";
    int position = 0;

    XmlElement* parseElement();

    map<string, XmlValue> parseAttributes();

    XmlValue* parseValue();

    static bool isWhiteSpace(char currentChar);

    string comp(string source);

};


#endif //XML_TO_JSON_XML_PARSER_H
