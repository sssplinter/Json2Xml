#include "JsonPresenter.h"

#define OFFSET 2

string JsonPresenter::convertToString(JsonObject *jsonObject) {
    string result;
    bool wasMain = main;
    if (main) {
        offset = 0;
    }
    main = false;
    if (!wasMain) {
        result += '\n';
    }
    result += getOffset();
    result += "{\n";
    offset += OFFSET;

    map<string, VirtualJsonItem *> jsonObjects = jsonObject->getValue();
    auto iter = jsonObjects.begin();
    if (!jsonObjects.empty()) {
        for (int i = 0; i < jsonObjects.size() - 1; i++) {
            string name = iter->first;
            VirtualJsonItem *value = iter->second;
            result += getOffset();
            result += '\"' + name + '\"' + " : ";
            result += convertToString(value);
            result += ",\n";
            iter++;
        }
        if (iter != jsonObjects.end()) {
            string name = iter->first;
            VirtualJsonItem *value = iter->second;
            result += getOffset();
            result += '\"' + name + '\"' + " : ";
            result += convertToString(value) + "\n";
        }
    }

    offset -= OFFSET;
    result += getOffset();
    result += "}";
    main = wasMain;
    return result;
}

string JsonPresenter::convertToString(JsonArray *jsonArray) {
    string result;
    offset += OFFSET;
    result += "\n" + getOffset() + "[\n";
    offset += OFFSET;
    list<VirtualJsonItem *> jsonObjects = jsonArray->getValue();
    auto iter = jsonObjects.begin();
    if (!jsonObjects.empty()) {
        for (int i = 0; i < jsonObjects.size() - 1; i++) {
            VirtualJsonItem *value = *iter;
            result += getOffset();
            result += ",\n";
            iter++;
        }
        if (iter != jsonObjects.end()) {
            VirtualJsonItem *value = *iter;
            result += convertToString(value);
        }
    }

    offset -= OFFSET;
    result += getOffset();
    offset -= OFFSET;
    result += "]";

    return result;
}

string JsonPresenter::convertToString(JsonPrimitive *jsonPrimitive) {
    string result;
    result += "\"" + jsonPrimitive->getValue() + "\"";
    return result;
}

string JsonPresenter::convertToString(VirtualJsonItem *jsonItem) {
    if (JsonObject *jsonObject = dynamic_cast<JsonObject *>(jsonItem)) {
        return convertToString(jsonObject);
    }
    if (JsonArray *jsonArray = dynamic_cast<JsonArray *>(jsonItem)) {
        return convertToString(jsonArray);
    }
    if (JsonPrimitive *jsonPrimitive = dynamic_cast<JsonPrimitive *>(jsonItem)) {
        return convertToString(jsonPrimitive);
    }
}

string JsonPresenter::getOffset() {
    string result;
    for (int i = 0; i < offset; i++) {
        result += ' ';
    }

    return result;
}

JsonPresenter::JsonPresenter() {
    main = true;
}
