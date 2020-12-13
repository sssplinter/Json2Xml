#include "XmlArray.h"
#include "XmlValue.h"

XmlType XmlArray::getType() {
    return XML_ARRAY;
}

void XmlArray::addValue(XmlObject *value) {
    if (XmlArray *xmlArray = dynamic_cast<XmlArray *>(value)) {
        list<XmlObject *> *arrayElements = xmlArray->getValue();
        int size = arrayElements->size();
        for (int i = 0; i < size; i++) {
            this->value->assign(arrayElements->begin(), arrayElements->end());
        }
    } else {
        this->value->push_back(value);
    }
}

XmlArray::XmlArray() {
    value = new list<XmlObject *>;
}

list<XmlObject *> *XmlArray::getValue() {
    return value;
}
