//
// Created by brinza on 25.03.2022.
//

#include "Stack.h"
#include "ListStack.h"
#include "VectorStack.h"
#include "StackImplementation.h"

#include <stdexcept>

Stack::Stack(StackContainer container)
        : _containerType(container)
{
    switch (container)
    {
        case StackContainer::List: {
            _pimpl = static_cast<IStackImplementation*>(new ListStack());
            break;
        }
        case StackContainer::Vector: {
            _pimpl = static_cast<IStackImplementation*>(new VectorStack());
            break;
        }
        default:
            throw std::runtime_error("Неизвестный тип контейнера");
    }
}

Stack::Stack(const ValueType* valueArray, const size_t arraySize, StackContainer container)
        : _containerType(container)
{
    switch (container)
    {
        case StackContainer::List: {
            _pimpl = static_cast<IStackImplementation*>(new ListStack(valueArray, arraySize));
            break;
        }
        case StackContainer::Vector: {
            _pimpl = static_cast<IStackImplementation*>(new VectorStack(valueArray, arraySize));
            break;
        }
        default:
            throw std::runtime_error("Неизвестный тип контейнера");
    }
}

Stack::Stack(const Stack& copyStack)
{
    _containerType = copyStack._containerType;
    *_pimpl = *copyStack._pimpl;
}

Stack& Stack::operator=(const Stack& copyStack)
{
    if (this != &copyStack) {
        _containerType = copyStack._containerType;
        delete _pimpl;
        *_pimpl = *copyStack._pimpl;
    }
    return *this;
}

Stack::Stack(Stack&& moveStack) noexcept {
    _containerType = moveStack._containerType;
    _pimpl = moveStack._pimpl;
}

Stack& Stack::operator=(Stack&& moveStack) noexcept {
    if (this != &moveStack) {
        _containerType = moveStack._containerType;
        delete _pimpl;
        _pimpl = moveStack._pimpl;
    }
    return *this;
}

Stack::~Stack()
{
    delete _pimpl;
}

void Stack::push(const ValueType& value)
{
    _pimpl->push(value);
}

void Stack::pop()
{
    _pimpl->pop();
}

const ValueType& Stack::top() const
{
    return _pimpl->top();
}

bool Stack::isEmpty() const
{
    return _pimpl->isEmpty();
}

size_t Stack::size() const
{
    return _pimpl->size();
}


