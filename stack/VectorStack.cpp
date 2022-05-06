//
// Created by brinza on 29.04.22.
//

#include "VectorStack.h"


VectorStack::VectorStack(const ValueType* valueArray, const size_t arraySize) {
    _vector.insert(_vector.begin(), valueArray, valueArray + arraySize);
}

void VectorStack::push(const ValueType& value) {
    _vector.push_back(value);
}

void VectorStack::pop() {
    _vector.pop_back();
}

const ValueType& VectorStack::top() const {
    return _vector.back();
}

bool VectorStack::isEmpty() const {
    return _vector.size() == 0;
}

size_t VectorStack::size() const {
    return _vector.size();
}
