#include "JsonArray.h"

void JsonArray::add(VirtualJsonItem *object) {
    value.push_back(object);
}

list<VirtualJsonItem*> JsonArray::getValue() {
    return value;
}

JSONType JsonArray::getType() {
    return ARRAY;
}
