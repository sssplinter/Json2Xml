#include "XmlElement.h"
#include "XmlArray.h"

XmlType XmlElement::getType() {
    return XML_ELEMENT;
}

XmlElement::XmlElement() {
    value = new map<string, XmlObject*>;
}

map<string, XmlObject *> *XmlElement::getValue() {
    return value;
}

void XmlElement::addObject(string objectName, XmlObject* objectValue) {
    if (value->count(objectName)) {
        XmlObject *xmlObject = value->at(objectName);
        XmlArray *xmlArray = new XmlArray();
        xmlArray->addValue(objectValue);
        xmlArray->addValue(xmlObject);
        value->insert(pair<string, XmlObject*>(objectName, xmlArray));
    } else {
        value->insert(pair<string, XmlObject*>(objectName, objectValue));
    }
}

