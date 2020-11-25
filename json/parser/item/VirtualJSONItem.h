//
// Created by krist on 24.11.2020.
//

#ifndef XML_TO_JSON_VIRTUALJSONITEM_H
#define XML_TO_JSON_VIRTUALJSONITEM_H

#include "Object.h"

enum JSONType {
    PRIMITIVE,
    OBJECT,
    ARRAY
};

template<typename T>
class VirtualJSONItem : public Object {
public:
    virtual T getValue();

    virtual JSONType getType();

};


#endif //XML_TO_JSON_VIRTUALJSONITEM_H
