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
    if(sourse[position] == ',') {
        position++;
    }
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
    JSONParser::sourse = comp(sourse);
    return parseObject();
}

JSONPrimitive JSONParser::parsePrimitive() {
    string stream;
    while (sourse[position] != ',' && sourse[position] != '}' && sourse[position] != ']') {
        stream += sourse[position];
        position++;
    }
    char curr = sourse[position];       // todo для отладки
    if (sourse[position] == ',') {
        position++;
    }
    JSONPrimitive primitive(stream);
    return primitive;
}

JSONObject JSONParser::parseObject() {
    position++;
    JSONObject jsonObject;
    string key;
    while (sourse[position] != '}') {
        key = parseKey();
        Object object = parseValue();
        jsonObject.put(key, object);
        if (sourse[position] == ',') {
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
