#include "JsonObject.h"

map<string, VirtualJsonItem *> JsonObject::getValue() {
    return value;
}
//массив и примитив
// по подобию

// примитив: значение- строка
// массив: зн - вектор обЪектов
JSONType JsonObject::getType() {
    return OBJECT;
}

void JsonObject::put(string key, VirtualJsonItem *val) {
    JsonObject::value.insert(pair<string, VirtualJsonItem *>(key, val));
}


//что объявлено, то уже создано