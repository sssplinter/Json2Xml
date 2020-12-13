#ifndef XML_TO_JSON_XMLARRAY_H
#define XML_TO_JSON_XMLARRAY_H

#include "XmlObject.h"
#include <list>

using namespace std;

class XmlArray : public XmlObject {
public:
    XmlArray();

    XmlType getType() override;

    void addValue(XmlObject *value);

    list<XmlObject*> *getValue();
private:
    list<XmlObject*>* value;
};


#endif //XML_TO_JSON_XMLARRAY_H
