#include "JSONParser.h"

string JSONParser::parseKey() {
    string stream;
    while (source[position] != ':') {
        stream += source[position];
        position++;
    }
    position++;

    return stream;
}

VirtualJsonItem* JSONParser::parseValue() {
    if(source[position] == ',') {
        position++;
    }
    const char c = source[position];
    if (c == '{') {
        return parseObject();
    } else if (c == '[') {
        return parseArray();
    } else {
        return parsePrimitive();
    }
}

JsonObject* JSONParser::parse(string sourse) {
    position = 0;
    JSONParser::source = comp(sourse);
    return parseObject();
}

JsonPrimitive* JSONParser::parsePrimitive() {
    string stream;
    while (source[position] != ',' && source[position] != '}' && source[position] != ']') {
        stream += source[position];
        position++;
    }
    if (source[position] == ',') {
        position++;
    }
    JsonPrimitive* primitive = new JsonPrimitive (stream);
    return primitive;
}

JsonObject* JSONParser::parseObject() {
    position++;
    JsonObject* jsonObject = new JsonObject();
    string key;
    while (source[position] != '}') {
        key = parseKey();
        VirtualJsonItem *object = parseValue();
        jsonObject->put(key, object);
        if (source[position] == ',') {
            position++;
        }
    }
    position++;

    return jsonObject;
}

JsonArray* JSONParser::parseArray() {
    position++;
    JsonArray* array = new JsonArray();
    while (source[position] != ']') {
        VirtualJsonItem* value = parseValue();
        array->add(value);
    }
    position++;
    return array;
}

string JSONParser::comp(string source) {
    string initialString = "";
    bool isString = false;
    int l = source.length();
    char currentChar;
    for (int i = 0; i < l; i++) {
        currentChar = source[i];
        if (currentChar == '"') {
            isString = !isString;
        }
        if ((!isString && !isWhiteSpace(currentChar)) || isString) {
            initialString += currentChar;
        }
    }
    return initialString; // строка или нестрока и пустое пространство
}

bool JSONParser::isWhiteSpace(char currentChar) {
    switch (currentChar) {
        case ' ':
        case '\n':
        case '\t':
        case '\r':
            return true;
        default:
            return false;
    }
}
