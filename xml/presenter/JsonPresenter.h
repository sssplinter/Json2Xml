#ifndef XML_TO_JSON_JSONPRESENTER_H
#define XML_TO_JSON_JSONPRESENTER_H


#include "../../json/parser/item/JsonObject.h"
#include "../../json/parser/item/JsonArray.h"
#include "../../json/parser/item/JsonPrimitive.h"

class JsonPresenter {
public:
    JsonPresenter();

    string convertToString(JsonObject *jsonObject);
private:
    int offset;
    bool main;
    string convertToString(JsonArray *jsonArray);

    string convertToString(JsonPrimitive *jsonPrimitive);

    string convertToString(VirtualJsonItem *jsonItem);

    string getOffset();

    bool isSpecialValue(string jsonString);

};


#endif //XML_TO_JSON_JSONPRESENTER_H
