#ifndef XML_TO_JSON_XMLTOJSONCONVERTER_H
#define XML_TO_JSON_XMLTOJSONCONVERTER_H


#include "../json/parser/item/JsonObject.h"
#include "../xml/parser/item/XmlElement.h"
#include "../xml/parser/item/XmlValue.h"
#include "../xml/parser/item/XmlArray.h"
#include "../json/parser/item/JsonArray.h"
#include "../json/parser/item/JsonPrimitive.h"

class XmlToJsonConverter {
public:
    JsonObject* convertJsonToXml(XmlElement *xmlElement);

    JsonArray* convertJsonToXml(XmlArray *xmlArray);
};


#endif //XML_TO_JSON_XMLTOJSONCONVERTER_H
