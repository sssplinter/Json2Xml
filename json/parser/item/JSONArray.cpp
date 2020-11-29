#include "JSONArray.h"

void JSONArray::add(Object object) {
    value.push_back(object);
}

list<Object> JSONArray::getValue() {
    return value;
}

JSONType JSONArray::getType() {
    return ARRAY;
}
