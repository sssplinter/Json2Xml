#ifndef XML_TO_JSON_JSONPARSER_H
#define XML_TO_JSON_JSONPARSER_H

#include "item/JsonObject.h"
#include "item/JsonArray.h"
#include "item/JsonPrimitive.h"

class JSONParser {
public:
    JsonObject* parse(string sourse);

private:
    string source;
    int position;

    string parseKey();           // распарсивает строку

    VirtualJsonItem* parseValue();

    JsonArray* parseArray();

    JsonObject* parseObject();

    JsonPrimitive*  parsePrimitive();    // числа и тд

    static bool isWhiteSpace(char currentChar);

    string comp(string source);

};


#endif
