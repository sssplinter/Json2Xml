#include "JsonPrimitive.h"

JsonPrimitive::JsonPrimitive(string value) {
    JsonPrimitive::value = value;
}

string JsonPrimitive::getValue() {
    return value;
}

JSONType JsonPrimitive::getType() {
    return PRIMITIVE;
}

