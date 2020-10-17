//
// Created by krist on 17.10.2020.
//

#ifndef XML_TO_JSON_INVALIDJSONEXCEPTION_H
#define XML_TO_JSON_INVALIDJSONEXCEPTION_H

#include <exception>

class InvalidJsonException : public std::exception {
private:
    const char *place;
public:
    InvalidJsonException(const char *place);

    const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT override;

};


#endif //XML_TO_JSON_INVALIDJSONEXCEPTION_H
