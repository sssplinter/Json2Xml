#include <iostream>
#include <string>

#include "json/parser/JsonParser.h"
#include "xml/parser/XmlParser.h"
#include "converter/JsonToXmlConverter.h"
#include "xml/presenter/XmlPresenter.h"
#include "xml/presenter/JsonPresenter.h"
#include "converter/XmlToJsonConverter.h"

using namespace std;

void isValid(string number);

int main() {
    string json = "{\n"
                  "  \"name\": \"Kristina\",\n"
                  "  \"friends\": [\n"
                  "    {\n"
                  "      \"name\": \"Stas\"\n"
                  "    },\n"
                  "    {\n"
                  "      \"name\": \"Yana\"\n"
                  "    }\n"
                  "  ]\n"
                  "}";

    string xml = "<root>\n"
                 "    <name>Kristina</name>\n"
                 "    <age>18</age>\n"
                 "</root>";
    isValid(xml);
    return 0;
}

void isValid(string number) {
    XmlParser parser;
    XmlToJsonConverter converter;
    JsonPresenter presenter;
    XmlElement* before = parser.parse(number);
    JsonObject* after = converter.convertJsonToXml(before);
    string result = presenter.convertToString(after);
    cout << result;
}