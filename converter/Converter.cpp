#include "Converter.h"
#include "../json/parser/item/JsonPrimitive.h"
#include "../xml/xml_parser/xml_item/XmlValue.h"

XmlElement *Converter::convertJsonToXml(JsonObject *jsonObject) {
    XmlElement *xmlElement = new XmlElement();
    map<string, VirtualJsonItem*> jsonObjects = jsonObject->getValue();
    for (auto iter = jsonObjects.begin(); iter != jsonObjects.end(); iter++) {
        string name = iter->first;
        VirtualJsonItem *object = iter->second;
        if (JsonPrimitive* jsonPrimitive = dynamic_cast<JsonPrimitive*>(object)) {
            string primitiveValue = jsonPrimitive->getValue();
            XmlValue *xmlValue = new XmlValue(primitiveValue);
            xmlElement->addObject(name, xmlValue);
        }
        if (JsonArray* castedJsonArray = dynamic_cast<JsonArray*>(object)) {
            XmlArray *xmlValue = convertJsonToXml(castedJsonArray);
            xmlElement->addObject(name, xmlValue);
        }
        if (JsonObject* castedJsonObject = dynamic_cast<JsonObject*>(object)) {
            XmlElement *xmlValue = convertJsonToXml(castedJsonObject);
            xmlElement->addObject(name, xmlValue);
        }
    }
    return xmlElement;
}

XmlArray *Converter::convertJsonToXml(JsonArray *jsonArray) {
    XmlArray *xmlArray = new XmlArray();
    list<VirtualJsonItem*> jsonObjects = jsonArray->getValue();
    for (auto iter = jsonObjects.begin(); iter != jsonObjects.end(); iter++) {
        VirtualJsonItem *object = *iter;
        if (JsonPrimitive* jsonPrimitive = dynamic_cast<JsonPrimitive*>(object)) {
            string primitiveValue = jsonPrimitive->getValue();
            XmlValue *xmlValue = new XmlValue(primitiveValue);
            xmlArray->addValue(xmlValue);
        }
        if (JsonArray* castedJsonArray = dynamic_cast<JsonArray*>(object)) {
            XmlArray *xmlValue = convertJsonToXml(castedJsonArray);
            xmlArray->addValue(xmlValue);
        }
        if (JsonObject* castedJsonObject = dynamic_cast<JsonObject*>(object)) {
            XmlObject *xmlValue = convertJsonToXml(castedJsonObject);
            xmlArray->addValue(xmlValue);
        }
    }
    return xmlArray;
}

