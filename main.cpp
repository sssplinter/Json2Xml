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
                  "  \"name\": \"sasha\",\n"
                  "  \"friends\": [\n"
                  "    {\n"
                  "      \"name\": \"kristina\",\n"
                  "    }\n"
                  "  ]\n"
                  "}";

    string xml = "<root>\n"
                 "    <friends>\n"
                 "        <root>\n"
                 "            <name>\n"
                 "                kristina\n"
                 "            </name>\n"
                 "        </root>\n"
                 "    </friends>\n"
                 "    <name>\n"
                 "        sasha\n"
                 "    </name>\n"
                 "</root>";
    isValid(json);
    return 0;
}

void isValid(string number) {
    JsonParser parser;
    JsonToXmlConverter converter;
    XmlPresenter presenter;
    JsonObject* before = parser.parse(number);
    XmlElement* after = converter.convertJsonToXml(before);
    string result = presenter.convertToString(after);
    cout << result;
}