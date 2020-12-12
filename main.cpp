#include <iostream>
#include <string>

#include "json/Numb_Validator.h"
#include "json/JSON_Validator.h"
#include "json/parser/JSONParser.h"
#include "xml/XML_Validator.h"
#include "xml/xml_parser/XML_Parser.h"

using namespace std;

void isValid(string number);

int main() {
    string str = "{\n"
                 "  \"name\": \"kristin\",\n"
                 "  \"age\": 18.34e-1,\n"
                 "  \"gay\": true,\n"
                 "  \"fiends\": [\n"
                 "    {\n"
                 "      \"name\": \"yana\",\n"
                 "      \"age\": 18\n"
                 "    },\n"
                 "    {\n"
                 "      \"name\": \"stas\",\n"
                 "      \"age\":  null,\n"
                 "      \"gay\": \"false\"\n"
                 "    }\n"
                 "  ]\n"
                 "  \n"
                 "}";

    string xml = "<root>"
                 "  <name>Kristina</name>"
                 "  <age>Kristina</age>"
                 "  <root>"
                 "      <name> Yana</name>"
                 "      <age> 18 </age>"
                 "      <gay> null</gay>"
                 "   </root>"
                 "</root>";
    isValid(xml);
    return 0;
}

void isValid(string number) {
//    JSONParser parser;
//    parser.parse(number);
    XML_Parser parser;
    XmlElement *res = parser.parse(number);
    if (res) {
        cout << "yeeeees" << endl;
    }

}