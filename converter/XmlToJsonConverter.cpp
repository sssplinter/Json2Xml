#include "XmlToJsonConverter.h"

#define OBJECT_NAME "root"

JsonObject *XmlToJsonConverter::convertJsonToXml(XmlElement *xmlElement) {
    JsonObject *jsonObject = new JsonObject();
    map<string, XmlObject *> *xmlObjects = xmlElement->getValue();
    for (auto iter = xmlObjects->begin(); iter != xmlObjects->end(); iter++) {
        string name = iter->first;
        XmlObject *xmlObject = iter->second;
        if (XmlValue *xmlValue = dynamic_cast<XmlValue *>(xmlObject)) {
            string value = xmlValue->getValue();
            JsonPrimitive *jsonPrimitive = new JsonPrimitive(value);
            jsonObject->put(name, jsonPrimitive);
        } else if (XmlArray *xmlArray = dynamic_cast<XmlArray *>(xmlObject)) {
            JsonArray *jsonArray = convertJsonToXml(xmlArray);
            jsonObject->put(name, jsonArray);
        } else if (XmlElement *xmlElem = dynamic_cast<XmlElement *>(xmlObject)){
            JsonObject *convertedJsonObject = convertJsonToXml(xmlElem);
            jsonObject->put(name, convertedJsonObject);
        }
    }

    return jsonObject;
}

JsonArray *XmlToJsonConverter::convertJsonToXml(XmlArray *xmlArray) {
    JsonArray *jsonArray = new JsonArray();
    list<XmlObject *> *xmlObjects = xmlArray->getValue();
    for (auto iter = xmlObjects->begin(); iter != xmlObjects->end(); iter++) {
        XmlObject *xmlObject = *iter;
        if (XmlValue *xmlValue = dynamic_cast<XmlValue *>(xmlObject)) {
            string value = xmlValue->getValue();
            JsonPrimitive *jsonPrimitive = new JsonPrimitive(value);
            jsonArray->add(jsonPrimitive);
        } else if (XmlArray *xmlArray = dynamic_cast<XmlArray *>(xmlObject)) {
            JsonArray *jsonArray = convertJsonToXml(xmlArray);
            jsonArray->add(jsonArray);
        } else if (XmlElement *xmlElem = dynamic_cast<XmlElement *>(xmlObject)){
            JsonObject *convertedJsonObject = convertJsonToXml(xmlElem);
            jsonArray->add(convertedJsonObject);
        }
    }

    return jsonArray;
}
