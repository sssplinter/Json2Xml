#ifndef XML_TO_JSON_CONVERTER_H
#define XML_TO_JSON_CONVERTER_H


#include "../xml/xml_parser/xml_item/XmlElement.h"
#include "../json/parser/item/JsonObject.h"

class Converter {
public:
    XmlElement* convertJsonToXml(JsonObject *jsonObject);
};


#endif //XML_TO_JSON_CONVERTER_H
