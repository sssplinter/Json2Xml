//
// Created by krist on 25.11.2020.
//

#ifndef XML_TO_JSON_JSONARRAY_H
#define XML_TO_JSON_JSONARRAY_H


#include "Object.h"
#include <list>

class JSONArray : public Object {
public:
    void add(Object object);
private:
    std::list<Object> value;
};


#endif //XML_TO_JSON_JSONARRAY_H
