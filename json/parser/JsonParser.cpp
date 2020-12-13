#include "JsonParser.h"

string JsonParser::parseKey() {
    string stream;
    while (source[position] != ':') {
        if (source[position] != '\"') {
            stream += source[position];
        }
        position++;
    }
    position++;

    return stream;
}

VirtualJsonItem* JsonParser::parseValue() {
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

JsonObject* JsonParser::parse(string source) {
    position = 0;
    JsonParser::source = comp(source);
    return parseObject();
}

JsonPrimitive* JsonParser::parsePrimitive() {
    string stream;
    while (source[position] != ',' && source[position] != '}' && source[position] != ']') {
        if (source[position] != '\"') {
            stream += source[position];
        }
        position++;
    }
    if (source[position] == ',') {
        position++;
    }
    JsonPrimitive* primitive = new JsonPrimitive (stream);
    return primitive;
}

JsonObject* JsonParser::parseObject() {
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

JsonArray* JsonParser::parseArray() {
    position++;
    JsonArray* array = new JsonArray();
    while (source[position] != ']') {
        VirtualJsonItem* value = parseValue();
        array->add(value);
    }
    position++;
    return array;
}

string JsonParser::comp(string source) {
    string initialString;
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

bool JsonParser::isWhiteSpace(char currentChar) {
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
