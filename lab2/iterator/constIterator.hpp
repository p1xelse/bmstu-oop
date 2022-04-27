#pragma once

#include <memory>

#include "constIterator.h"  // NOLINT
#include "exceptions.h"

template <typename T>
constIterator<T>::constIterator() {
    this->cur.lock() = nullptr;
}

template <typename T>
constIterator<T>::constIterator(const std::shared_ptr<SetNode<T>>& node) {
    cur = node;
}

template <typename T>
constIterator<T>::constIterator(const constIterator<T>& iterator) {
    iterator.checkExpired(__FUNCTION__);
    cur = iterator.cur.lock();
}

template <typename T>
constIterator<T>::operator bool() const {
    return !cur.expired();
}

template <typename T>
SetNode<T>& constIterator<T>::getCurNode() const {
    checkExpired(__FUNCTION__);

    return *(cur.lock());
}

template <typename T>
void constIterator<T>::next() {
    checkExpired(__FUNCTION__);

    cur = getCurNode().getNext();
}

template <typename T>
void constIterator<T>::prev() {
    checkExpired(__FUNCTION__);

    cur = getCurNode().getPrev();
}

template <typename T>
constIterator<T>& constIterator<T>::operator++() {
    checkExpired(__FUNCTION__);

    this->next();
    return *this;
}

template <typename T>
constIterator<T> constIterator<T>::operator++(int) {
    checkExpired(__FUNCTION__);

    auto result = *this;
    this->next();
    return result;
}

template <typename T>
constIterator<T>& constIterator<T>::operator--() {
    checkExpired(__FUNCTION__);

    this->prev();
    return *this;
}

template <typename T>
constIterator<T> constIterator<T>::operator--(int) {
    checkExpired(__FUNCTION__);

    auto result = *this;
    this->prev();
    return result;
}

template <typename T>
const T& constIterator<T>::operator*() const {
    checkExpired(__FUNCTION__);

    return getCurNode().getValue();
}

template <typename T>
const T* constIterator<T>::operator->() const {
    checkExpired(__FUNCTION__);

    return &(operator*());
}

template <typename T>
bool constIterator<T>::operator==(const constIterator<T>& other) const {
    return cur.lock() == other.cur.lock();
}

template <typename T>
bool constIterator<T>::operator!=(const constIterator<T>& other) const {
    return !(*this == other);
}

template <typename T>
constIterator<T>& constIterator<T>::operator=(const constIterator<T>& other) {
    cur = other.cur;
    return *this;
}

template <typename T>
std::shared_ptr<SetNode<T>> constIterator<T>::getNodePointer() const {
    checkExpired(__FUNCTION__);

    return cur.lock();
}

template <typename T>
bool constIterator<T>::checkExpired(const std::string& func) const {
    if (*this) {
        return true;
    }

    throw DeletedObjExeption(__TIME__, __FILE__, typeid(*this).name(), func);

    return false;
}
