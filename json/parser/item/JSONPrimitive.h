#ifndef XML_TO_JSON_JSONPRIMITIVE_H
#define XML_TO_JSON_JSONPRIMITIVE_H


#include "VirtualJSONItem.h"
#include <string>

using namespace std;
class JSONPrimitive : public VirtualJSONItem<string>{
public:
    JSONPrimitive(string value);

    string getValue() override;

    JSONType getType() override;

private:
    string value;

};


#endif //XML_TO_JSON_JSONPRIMITIVE_H
