#ifndef XML_TO_JSON_JSONTOXMLCONVERTER_H
#define XML_TO_JSON_JSONTOXMLCONVERTER_H


#include "../xml/parser/item/XmlElement.h"
#include "../xml/parser/item/XmlArray.h"
#include "../json/parser/item/JsonObject.h"
#include "../json/parser/item/JsonArray.h"

class JsonToXmlConverter {
public:
    XmlElement* convertJsonToXml(JsonObject *jsonObject);

    XmlArray* convertJsonToXml(JsonArray *jsonArray);
};


#endif //XML_TO_JSON_JSONTOXMLCONVERTER_H
