//
// Created by krist on 25.11.2020.
//

#include "JSONObject.h"

map<string, Object> JSONObject::getValue() {
    return value;
}
//массив и примитив
// по подобию

// примитив: значение- строка
// массив: зн - вектор обЪектов
JSONType JSONObject::getType() {
    return OBJECT;
}

void JSONObject::put( string key, Object val) {
    JSONObject::value.insert(pair<string, Object>());
}


//что объявлено, то уже создано