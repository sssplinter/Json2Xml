//
// Created by krist on 25.11.2020.
//

#ifndef XML_TO_JSON_JSONPRIMITIVE_H
#define XML_TO_JSON_JSONPRIMITIVE_H


#include "Object.h"
#include <string>

using namespace std;
class JSONPrimitive : public Object{
public:
    JSONPrimitive(string value);
private:
    string value;

};


#endif //XML_TO_JSON_JSONPRIMITIVE_H
