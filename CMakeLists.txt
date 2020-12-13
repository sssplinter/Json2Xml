cmake_minimum_required(VERSION 3.14)
project(XML_to_JSON)

set(CMAKE_CXX_STANDARD 14)

add_executable(XML_to_JSON main.cpp
        json/JSON_Validator.cpp json/JSON_Validator.h
        json/InvalidJsonException.cpp json/InvalidJsonException.h json/Numb_Validator.cpp json/Numb_Validator.h json/InvalidJsonNumberException.cpp json/InvalidJsonNumberException.h xml/XmlValidator.cpp xml/XmlValidator.h utils/Redactor.cpp utils/Redactor.h json/parser/item/VirtualJsonItem.h json/parser/JSONParser.cpp json/parser/JSONParser.h json/parser/item/JsonObject.cpp json/parser/item/JsonObject.h json/parser/item/JsonArray.cpp json/parser/item/JsonArray.h json/parser/item/JsonPrimitive.cpp json/parser/item/JsonPrimitive.h xml/parser/XmlParser.cpp xml/parser/XmlParser.h xml/parser/item/XmlElement.cpp xml/parser/item/XmlElement.h xml/parser/item/XmlValue.cpp xml/parser/item/XmlValue.h xml/parser/item/XmlObject.cpp xml/parser/item/XmlObject.h xml/parser/item/XmlArray.cpp xml/parser/item/XmlArray.h converter/JsonToXmlConverter.cpp converter/JsonToXmlConverter.h xml/presenter/XmlPresenter.cpp xml/presenter/XmlPresenter.h xml/presenter/JsonPresenter.cpp xml/presenter/JsonPresenter.h converter/XmlToJsonConverter.cpp converter/XmlToJsonConverter.h)