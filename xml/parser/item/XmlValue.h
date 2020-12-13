#ifndef XML_TO_JSON_XMLVALUE_H
#define XML_TO_JSON_XMLVALUE_H

#include <string>
#include "XmlObject.h"

using namespace std;

class XmlValue : public XmlObject{
public:
    XmlValue(string &value);

    XmlType getType() override;

    string getValue();
private:
    string value;
};

#endif //XML_TO_JSON_XMLVALUE_H
