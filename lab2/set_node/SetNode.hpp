#pragma once
#include "SetNode.h"

template <typename T>
SetNode<T>::SetNode(const T value) : value(value) {}

template <typename T>
SetNode<T>::SetNode(std::shared_ptr<SetNode<T>> &node)
    : SetNode<T>(node.value) {
    next = node.next;
    prev = node.prev;
}

template <typename T>
void SetNode<T>::set(const T &valueData) {
    value = valueData;
}

template <typename T>
void SetNode<T>::setNext(const SetNode<T> &node) {
    next = std::make_shared<SetNode<T>>(node);
}

template <typename T>
void SetNode<T>::setNext(std::shared_ptr<SetNode<T>> &node) {
    next = node;
}

template <typename T>
void SetNode<T>::setNextNull() {
    next = nullptr;
}

template <typename T>
void SetNode<T>::setPrev(const SetNode<T> &node) {
    prev = std::make_shared<SetNode<T>>(node);
}

template <typename T>
void SetNode<T>::setPrev(std::shared_ptr<SetNode<T>> &node) {
    prev = node;
}

template <typename T>
void SetNode<T>::setPrevNull() {
    prev = nullptr;
}

template <typename T>
void SetNode<T>::setNull() {
    prev = nullptr;
    next = nullptr;
}

template <typename T>
void SetNode<T>::remove() {
    if (next) {
        next->prev = prev;
    }
    if (prev) {
        prev->next = next;
    }
}

template <typename T>
std::shared_ptr<SetNode<T>> SetNode<T>::getNext() const {
    return next;
}

template <typename T>
std::shared_ptr<SetNode<T>> SetNode<T>::getPrev() const {
    return prev;
}

template <typename T>
const T &SetNode<T>::getValue() const {
    return value;
}

template <typename T>
bool SetNode<T>::operator==(const std::shared_ptr<SetNode<T>> &node) const {
    return this == node;
}

template <typename T>
bool SetNode<T>::operator!=(const std::shared_ptr<SetNode<T>> &node) const {
    return this != node;
}
