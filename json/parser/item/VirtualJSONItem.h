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

template<typename T>
T VirtualJSONItem<T>::getValue() {
    T t;
    return t;
}

template<typename T>
JSONType VirtualJSONItem<T>::getType() {
    return PRIMITIVE;
}


#endif //XML_TO_JSON_VIRTUALJSONITEM_H