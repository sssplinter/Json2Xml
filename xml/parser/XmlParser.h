#include <string>
#include <map>
#include "item/XmlObject.h"
#include "item/XmlValue.h"
#include "item/XmlElement.h"

#ifndef XML_TO_JSON_XML_PARSER_H
#define XML_TO_JSON_XML_PARSER_H

using namespace std;

class XmlParser {
public:
    XmlElement* parse(string &str);
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
