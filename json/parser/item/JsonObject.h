#include <string>
#include <map>
#include "VirtualJSONItem.h"

#ifndef XML_TO_JSON_JSONOBJECT_H
#define XML_TO_JSON_JSONOBJECT_H

using namespace std;

class JSONObject : public VirtualJSONItem<map<string, Object> > {
public:
    map<string, Object> getValue();

    JSONType getType();

    void put(string key, Object value);

private:
    map<string, Object> value;
};


#endif //XML_TO_JSON_JSONOBJECT_H
