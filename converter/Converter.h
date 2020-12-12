#ifndef XML_TO_JSON_CONVERTER_H
#define XML_TO_JSON_CONVERTER_H


#include "../xml/xml_parser/xml_item/XmlElement.h"
#include "../xml/xml_parser/xml_item/XmlArray.h"
#include "../json/parser/item/JsonObject.h"
#include "../json/parser/item/JsonArray.h"

class Converter {
public:
    XmlElement* convertJsonToXml(JsonObject *jsonObject);

    XmlArray* convertJsonToXml(JsonArray *jsonArray);
};


#endif //XML_TO_JSON_CONVERTER_H
