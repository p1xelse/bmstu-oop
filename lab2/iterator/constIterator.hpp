#pragma once

#include <memory>
#include "constIterator.h"   // NOLINT

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
    cur = iterator.cur.lock();
}

template <typename T>
constIterator<T>::operator bool() const {
    return cur.lock()->getNext() != nullptr;
}

template <typename T>
SetNode<T>& constIterator<T>::getCurNode() const {
    return *(cur.lock());
}

template <typename T>
void constIterator<T>::next() {
    cur = getCurNode().getNext();
}

template <typename T>
void constIterator<T>::prev() {
    cur = getCurNode().getPrev();
}

template <typename T>
constIterator<T>& constIterator<T>::operator++() {
    this->next();
    return *this;
}

template <typename T>
constIterator<T> constIterator<T>::operator++(int) {
    auto result = *this;
    this->next();
    return result;
}

template <typename T>
constIterator<T>& constIterator<T>::operator--() {
    this->prev();
    return *this;
}

template <typename T>
constIterator<T> constIterator<T>::operator--(int) {
    auto result = *this;
    this->prev();
    return result;
}

template <typename T>
const T& constIterator<T>::operator*() const {
    return getCurNode().getValue();
}

template <typename T>
const T* constIterator<T>::operator->() const {
    return &(operator*());
}

template <typename T>
bool constIterator<T>::operator==(const constIterator<T> &other) const {
    return cur.lock() == other.cur.lock();
}

template <typename T>
bool constIterator<T>::operator!=(const constIterator<T> &other) const {
    return !(*this == other);
}

template <typename T>
constIterator<T>& constIterator<T>::operator=(const constIterator<T> &other) const {
    cur = other.lock();
    return *this;
}

template <typename T>
std::shared_ptr<SetNode<T>> constIterator<T>::getNodePointer() const {
    return cur.lock();
}
