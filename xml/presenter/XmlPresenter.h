#ifndef XML_TO_JSON_XMLPRESENTER_H
#define XML_TO_JSON_XMLPRESENTER_H

#include "string"
#include "../xml_parser/xml_item/XmlElement.h"
#include "../xml_parser/xml_item/XmlArray.h"
#include "../xml_parser/xml_item/XmlValue.h"

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
