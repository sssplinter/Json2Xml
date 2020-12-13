#include "XmlValue.h"

XmlType XmlValue::getType() {
    return XML_VALUE;
}

XmlValue::XmlValue(string &value) : value(value) {

}

string XmlValue::getValue() {
    return value;
}


