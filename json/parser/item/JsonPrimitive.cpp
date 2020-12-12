#include "JSONPrimitive.h"

JSONPrimitive::JSONPrimitive(string value) {
    JSONPrimitive::value = value;
}

string JSONPrimitive::getValue() {
    return value;
}

JSONType JSONPrimitive::getType() {
    return PRIMITIVE;
}

