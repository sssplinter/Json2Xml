#ifndef XML_TO_JSON_JSONARRAY_H
#define XML_TO_JSON_JSONARRAY_H


#include "VirtualJsonItem.h"
#include <list>

using namespace std;

class JsonArray : public VirtualJsonItem {
public:
    void add(VirtualJsonItem *object);

    list<VirtualJsonItem *> getValue();

    JSONType getType() override;

private:
    list<VirtualJsonItem *> value;
};


#endif //XML_TO_JSON_JSONARRAY_H
