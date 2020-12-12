//
// Created by krist on 18.10.2020.
//

#ifndef XML_TO_JSON_XML_VALIDATOR_H
#define XML_TO_JSON_XML_VALIDATOR_H

#include <string>
#include <stack>

using namespace std;

class XML_Validator {
private:
    stack<string> xm_stack;

    void checkProlog(string &xmlStr);//todo

    void checkElement(string &check_str);

    void checkAttribute(string &check_str);//todo

    void checkValue(string &check_str);

    string take_tag(string &check_str);

    bool compare_tags(string check_str);

public:

    bool checkXML(string xmlStr);


};

#endif //XML_TO_JSON_XML_VALIDATOR_H
