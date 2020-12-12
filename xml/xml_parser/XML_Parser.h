#include <string>
#include <map>
#include "xml_item/XmlObject.h"
#include "xml_item/XmlValue.h"

#ifndef XML_TO_JSON_XML_PARSER_H
#define XML_TO_JSON_XML_PARSER_H

using namespace std;

class XML_Parser {
public:
    map<string, XmlObject> parse(string &xml_str);
private:

    string source = "";
    int position = 0;

    map<string, XmlObject> parseElement();

    map<string, XmlValue> parseAttributes();

    XmlValue parseValue();

};


#endif //XML_TO_JSON_XML_PARSER_H
