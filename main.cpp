#include <iostream>
#include <string>

#include "json/parser/JSONParser.h"
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
    isValid(xml);
    return 0;
}

void isValid(string number) {
    XmlParser jsonParser;
    XmlToJsonConverter converter;
    JsonPresenter presenter;
    XmlElement* xmlElement = jsonParser.parse(number);
    JsonObject* jsonObject = converter.convertJsonToXml(xmlElement);
    string result = presenter.convertToString(jsonObject);
    cout << result;
}