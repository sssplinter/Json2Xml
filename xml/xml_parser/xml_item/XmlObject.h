#ifndef XML_TO_JSON_XMLOBJECT_H
#define XML_TO_JSON_XMLOBJECT_H

enum XmlType {
    XML_ARRAY,
    XML_VALUE,
    XML_ELEMENT,
    XML_OBJECT
};

class XmlObject {
public:
    virtual XmlType getType();
};


#endif
