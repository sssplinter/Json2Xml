#include "XmlValue.h"

bool XmlValue::isElement() {
    return false;
}

XmlValue::XmlValue(string &value) : value(value) {

}

string XmlValue::getValue() {
    return value;
}


