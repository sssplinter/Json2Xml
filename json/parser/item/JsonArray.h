#ifndef XML_TO_JSON_JSONARRAY_H
#define XML_TO_JSON_JSONARRAY_H


#include "VirtualJSONItem.h"
#include <list>

using namespace std;

class JSONArray : public VirtualJSONItem<list<Object>> {
public:
    void add(Object object);

    list<Object> getValue() override;

    JSONType getType() override;

private:
    std::list<Object> value;
};


#endif //XML_TO_JSON_JSONARRAY_H
