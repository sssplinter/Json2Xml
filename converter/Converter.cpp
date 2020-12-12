#include "Converter.h"
#include "../json/parser/item/JsonPrimitive.h"
#include "../json/parser/item/VirtualJsonItem.h"

XmlElement *Converter::convertJsonToXml(JsonObject *jsonObject) {
    XmlElement *xmlElement = new XmlElement();
    map<string, VirtualJsonItem*> jsonObjects = jsonObject->getValue();
    for (auto iter = jsonObjects.begin(); iter != jsonObjects.end(); iter++) {
        string name = iter->first;
        VirtualJsonItem *object = iter->second;
        if (JsonPrimitive* jsonPrimitive = dynamic_cast<JsonPrimitive*>(object)) {

        }
    }
}
