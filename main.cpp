#include <iostream>
#include <string>

#include "json/Numb_Validator.h"
#include "json/JSON_Validator.h"

using namespace std;

bool isValid(string number);

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
    cout<<isValid(str);
    return 0;
}

bool isValid(string number) {
    JSON_Validator validator;
    return validator.checkObject(number);
}