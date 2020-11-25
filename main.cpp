#include <iostream>
#include <string>

#include "json/Numb_Validator.h"
#include "json/JSON_Validator.h"
#include "json/parser/JSONParser.h"

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
    isValid(str);
    return 0;
}

void isValid(string number) {
    JSONParser parser;
    parser.parse(number);
}