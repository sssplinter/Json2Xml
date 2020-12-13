#ifndef XML_TO_JSON_XMLPRESENTER_H
#define XML_TO_JSON_XMLPRESENTER_H

#include "string"
#include "../parser/item/XmlElement.h"
#include "../parser/item/XmlArray.h"
#include "../parser/item/XmlValue.h"

using namespace std;

class XmlPresenter {
public:
    string convertToString(XmlElement *xmlElement);
private:
    int offset;
    bool rooted;
    string convertToString(XmlArray *xmlArray);

    string convertToString(XmlValue *xmlValue);

    string getOffset();
};


#endif //XML_TO_JSON_XMLPRESENTER_H
