#ifndef XML_TO_JSON_JSONPRIMITIVE_H
#define XML_TO_JSON_JSONPRIMITIVE_H


#include "VirtualJsonItem.h"
#include <string>

using namespace std;
class JsonPrimitive : public VirtualJsonItem{
public:
    JsonPrimitive(string value);

    string getValue();

    JSONType getType() override;

private:
    string value;

};


#endif //XML_TO_JSON_JSONPRIMITIVE_H
