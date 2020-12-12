#ifndef XML_TO_JSON_VIRTUALJSONITEM_H
#define XML_TO_JSON_VIRTUALJSONITEM_H


enum JSONType {
    PRIMITIVE,
    OBJECT,
    ARRAY
};

class VirtualJsonItem {
public:
    virtual JSONType getType() {
        return PRIMITIVE;
    }
};




#endif //XML_TO_JSON_VIRTUALJSONITEM_H