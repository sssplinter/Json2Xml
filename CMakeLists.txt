cmake_minimum_required(VERSION 3.14)
project(XML_to_JSON)

set(CMAKE_CXX_STANDARD 14)

add_executable(XML_to_JSON main.cpp
        json/JSON_Validator.cpp json/JSON_Validator.h
        json/InvalidJsonException.cpp json/InvalidJsonException.h json/Numb_Validator.cpp json/Numb_Validator.h json/InvalidJsonNumberException.cpp json/InvalidJsonNumberException.h xml/XML_Validator.cpp xml/XML_Validator.h parser/objectParser/ObjectParser.cpp parser/objectParser/ObjectParser.h parser/arrayParser/ArrayParser.cpp parser/arrayParser/ArrayParser.h parser/numbParser/NumberParser.cpp parser/numbParser/NumberParser.h parser/nullParser/NullParser.cpp parser/nullParser/NullParser.h utils/Redactor.cpp utils/Redactor.h json/parser/VirtualParser.h json/parser/item/VirtualJSONItem.h json/parser/JSONParser.cpp json/parser/JSONParser.h json/parser/item/JSONObject.cpp json/parser/item/JSONObject.h json/parser/item/Object.h json/parser/item/JSONArray.cpp json/parser/item/JSONArray.h json/parser/item/JSONPrimitive.cpp json/parser/item/JSONPrimitive.h xml/xml_parser/XML_Parser.cpp xml/xml_parser/XML_Parser.h xml/xml_parser/xml_item/XmlElement.cpp xml/xml_parser/xml_item/XmlElement.h xml/xml_parser/xml_item/XmlValue.cpp xml/xml_parser/xml_item/XmlValue.h xml/xml_parser/xml_item/XmlObject.cpp xml/xml_parser/xml_item/XmlObject.h xml/xml_parser/xml_item/XmlArray.cpp xml/xml_parser/xml_item/XmlArray.h)