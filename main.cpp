#include <iostream>
#include <string>

#include "json/parser/JSONParser.h"
#include "xml/xml_parser/XML_Parser.h"
#include "converter/Converter.h"
#include "xml/presenter/XmlPresenter.h"

using namespace std;

void isValid(string number);

int main() {
    string json = "{\n"
                  "  \"name\": \"sasha\",\n"
                  "  \"age\": 1,\n"
                  "  \"friends\": [\n"
                  "    {\n"
                  "      \"name\": \"kristina\",\n"
                  "      \"age\": 2,\n"
                  "    },\n"
                  "    {\n"
                  "      \"name\": \"stas\",\n"
                  "      \"age\": 3,\n"
                  "    }\n"
                  "  ]\n"
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
    isValid(json);
    return 0;
}

void isValid(string number) {
    JSONParser jsonParser;
    Converter converter;
    XmlPresenter xmlPresenter;
    JsonObject* jsonObject = jsonParser.parse(number);
    XmlElement* xmlElement = converter.convertJsonToXml(jsonObject);
    string result = xmlPresenter.convertToString(xmlElement);
    cout << result;
}