cmake_minimum_required(VERSION 3.14)
project(XML_to_JSON)

set(CMAKE_CXX_STANDARD 14)

add_executable(XML_to_JSON main.cpp
        json/JSON_Validator.cpp json/JSON_Validator.h
        json/InvalidJsonException.cpp json/InvalidJsonException.h json/Numb_Validator.cpp json/Numb_Validator.h json/InvalidJsonNumberException.cpp json/InvalidJsonNumberException.h)