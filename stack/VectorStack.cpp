//
// Created by brinza on 29.04.22.
//

#include "VectorStack.h"


VectorStack::VectorStack(const ValueType* valueArray, const size_t arraySize) {
    _vector.insert(valueArray, arraySize, 0);
}

void VectorStack::push(const ValueType& value) {
    _vector.pushBack(value);
}

void VectorStack::pop() {
    _vector.popBack();
}

const ValueType& VectorStack::top() const {
    return _vector[_vector.size() - 1];
}

bool VectorStack::isEmpty() const {
    return _vector.size() == 0;
}

size_t VectorStack::size() const {
    return _vector.size();
}
