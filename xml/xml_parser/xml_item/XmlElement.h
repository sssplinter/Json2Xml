#ifndef XML_TO_JSON_XMLELEMENT_H
#define XML_TO_JSON_XMLELEMENT_H

#include <string>
#include <map>
#include "XmlObject.h"

using namespace std;

class XmlElement : public XmlObject {
public:
    XmlElement();

    XmlType getType() override;

    void addObject(string objectName, XmlObject *objectValue);

    map<string, XmlObject *> *getValue();

private:
    map<string, XmlObject *> *value;
};


#endif
