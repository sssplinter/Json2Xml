//
// Created by krist on 24.11.2020.
//

#include <sstream>
#include <list>
#include "JSONParser.h"

string JSONParser::parseKey() {
    string stream;
    while (sourse[position] != ':') {
        stream += sourse[position];
        position++;
    }
    position++;

    return stream;
}

Object JSONParser::parseValue() {
    const char c = sourse[position];
    if (c == '{') {
        return parseObject();
    } else if (c == '[') {
        return parseArray();
    } else {
        return parsePrimitive();
    }
}

JSONObject JSONParser::parse(string sourse) {
    position = 0;
    JSONParser::sourse = sourse;
    return parseObject();
}

JSONPrimitive JSONParser::parsePrimitive() {
    string stream;
    while (sourse[position] != ',' && sourse[position] != '}' && sourse[position] != ']') {
        stream += sourse[position];
        position++;
    }
    position++;
    JSONPrimitive primitive(stream);
    return primitive;
}

JSONObject JSONParser::parseObject() {
    position++;
    JSONObject jsonObject;
    while (sourse[position] != '}') {
        string key = parseKey();
        Object object = parseValue();
        jsonObject.put(key, object);
        if (sourse[position == ',']) {
            position++;
        }
    }
    position++;

    return jsonObject;
}

JSONArray JSONParser::parseArray() {
    position++;
    JSONArray array;
    while (sourse[position] != ']') {
        Object value = parseValue();
        array.add(value);
        if (sourse[position] != ',') {
            position++;
        }
    }
    return array;
}
