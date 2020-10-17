//
// Created by krist on 17.10.2020.
//

#ifndef XML_TO_JSON_INVALIDJSONNUMBEREXCEPTION_H
#define XML_TO_JSON_INVALIDJSONNUMBEREXCEPTION_H


#include "InvalidJsonException.h"

class InvalidJsonNumberException : public InvalidJsonException {
public:
    InvalidJsonNumberException(const char *place);
};


#endif //XML_TO_JSON_INVALIDJSONNUMBEREXCEPTION_H
