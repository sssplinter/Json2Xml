//
// Created by krist on 24.11.2020.
//

#ifndef XML_TO_JSON_JSONPARSER_H
#define XML_TO_JSON_JSONPARSER_H


#include "item/JSONObject.h"
#include "item/JSONArray.h"
#include "item/JSONPrimitive.h"

class JSONParser {
public:
    JSONObject parse(string sourse);

private:
    string sourse;
    int position;

    string parseKey();           // распарсивает строку

    Object parseValue();

    JSONArray parseArray();

    JSONObject parseObject();

    JSONPrimitive  parsePrimitive();    // числа и тд

    void compress();
};


#endif //XML_TO_JSON_JSONPARSER_H