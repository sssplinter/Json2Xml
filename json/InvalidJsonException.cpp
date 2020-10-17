//
// Created by krist on 17.10.2020.
//

#include "InvalidJsonException.h"

const char *InvalidJsonException::what() const _GLIBCXX_USE_NOEXCEPT {
    return this->place;
}

InvalidJsonException::InvalidJsonException(const char *place) {
    this->place = place;
}

