#include <string>
#include <map>
#include "VirtualJsonItem.h"

#ifndef XML_TO_JSON_JSONOBJECT_H
#define XML_TO_JSON_JSONOBJECT_H

using namespace std;

class JsonObject : public VirtualJsonItem {
public:
    map<string, VirtualJsonItem *> getValue();

    JSONType getType();

    void put(string key, VirtualJsonItem *value);

private:
    map<string, VirtualJsonItem *> value;
};


#endif //XML_TO_JSON_JSONOBJECT_H
