#pragma once

#include "Set.h"

template <typename T>
constIterator<T> Set<T>::cbegin() const {
    if (head != nullptr) {
        return constIterator<T>(head);
    }
    return constIterator<T>();
}

template <typename T>
constIterator<T> Set<T>::cend() const {
    if (tail != nullptr) {
        return constIterator<T>(tail->getNext());
    }

    return constIterator<T>();
}


template <typename T>
Set<T>::Set(const Set<T> &other) {
    for (auto iter = other.cbegin(); iter != other.cend(); ++iter) {
        std::shared_ptr<SetNode<T>> tmpNode = nullptr;

        try {
            tmpNode = std::shared_ptr<SetNode<T>>(new SetNode<T>(*iter));
        } catch (const std::bad_alloc &exeption) {
            throw BadAllocateMemory(__TIME__, __FILE__, typeid(*this).name(),
                                    __FUNCTION__);
        }

        append(tmpNode);
    }
}

template <typename T>
Set<T>::Set(Set<T> &&other) noexcept(false)
    : head(other.head), tail(other.tail) {
    this->size = other.size;
}

template <typename T>
Set<T>::Set(std::initializer_list<T> elems) {
    for (auto elem : elems) {
        append(elem);
    }
}

template <typename T>
Set<T>::~Set() {
    clear();
}

template <typename T>
constIterator<T> Set<T>::find(const T &val) const {
    auto iter = cbegin();
    for (; iter != cend() && *iter != val; ++iter) {
    }

    return iter;
}

template <typename T>
bool Set<T>::append(const std::shared_ptr<SetNode<T>> &node) noexcept(false) {
    std::shared_ptr<SetNode<T>> tmpNode = nullptr;
    std::shared_ptr<SetNode<T>> capNode = nullptr;

    try {
        tmpNode = std::shared_ptr<SetNode<T>>(new SetNode<T>(node->getValue()));

        if (empty()) capNode = std::shared_ptr<SetNode<T>>(new SetNode<T>(T{}));
    } catch (const std::bad_alloc &exeption) {
        throw BadAllocateMemory(__TIME__, __FILE__, typeid(*this).name(),
                                __FUNCTION__);
    }

    if (empty()) {
        head = tmpNode;
        head->setNext(capNode);
        tail = head;
        capNode->setPrev(tail);
        size++;

        return true;
    }

    if (find(tmpNode->getValue()) != cend()) {
        return false;
    }

    tmpNode->setPrev(tail);

    capNode = tail->getNext();
    capNode->setPrev(tmpNode);
    tmpNode->setNext(capNode);

    tail->setNext(tmpNode);
    tail = tmpNode;
    size++;

    return true;
}

template <typename T>
bool Set<T>::append(const T &value) noexcept(false) {
    std::shared_ptr<SetNode<T>> tmpNode = nullptr;

    try {
        tmpNode = std::shared_ptr<SetNode<T>>(new SetNode<T>(value));
    } catch (const std::bad_alloc &exeption) {
        throw BadAllocateMemory(__TIME__, __FILE__, typeid(*this).name(),
                                __FUNCTION__);
    }

    return append(tmpNode);
}

template <typename T>
bool Set<T>::append(T &&value) noexcept(false) {
    return append(value);
}

template <typename T>
void Set<T>::append(std::initializer_list<T> initList) noexcept(false) {
    for (auto elem : initList) {
        std::shared_ptr<SetNode<T>> tmpNode = nullptr;

        try {
            tmpNode = std::shared_ptr<SetNode<T>>(new SetNode<T>(elem));
        } catch (const std::bad_alloc &exeption) {
            throw BadAllocateMemory(__TIME__, __FILE__, typeid(*this).name(),
                                    __FUNCTION__);
        }

        append(tmpNode);
    }
}

template <typename T>
void Set<T>::append(T *initArr, size_t len) noexcept(false) {
    for (size_t i = 0; i < len; ++i) {
        append(initArr[i]);
    }
}

template <typename T>
Set<T> Set<T>::update(const T &value) noexcept(false) {
    Set<T> newSet(*this);
    newSet.append(value);

    return newSet;
}
template <typename T>
Set<T> Set<T>::update(T &&value) noexcept(false) {
    return update(value);
}

template <typename T>
Set<T> Set<T>::update(std::initializer_list<T> initList) noexcept(false) {
    Set<T> newSet(*this);

    for (auto elem : initList) {
        newSet.append(elem);
    }

    return newSet;
}

template <typename T>
Set<T> Set<T>::update(T *initArr, size_t len) noexcept(false) {
    Set<T> newSet(*this);

    for (size_t i = 0; i < len; ++i) {
        newSet.append(initArr[i]);
    }

    return newSet;
}

template <typename T>
Set<T> &Set<T>::operator+=(const Set<T> &other) {
    for (auto iter = other.cbegin(); iter != other.cend(); ++iter) {
        append(*iter);
    }

    return *this;
}

template <typename T>
Set<T> &Set<T>::operator+=(const T &data) {
    append(data);

    return *this;
}

template <typename T>
Set<T> Set<T>::operator+(const Set<T> &other) const {
    Set<T> newSet(*this);
    newSet += other;

    return newSet;
}

template <typename T>
Set<T> Set<T>::operator+(const T &data) const {
    Set<T> newSet(*this);
    newSet += data;

    return newSet;
}

template <typename T>
Set<T> Set<T>::intersect(const Set<T> &other) const {
    return *this & other;
}

template <typename T>
Set<T> Set<T>::intersect(const T &data) const {
    return *this & data;
}

template <typename T>
Set<T> Set<T>::operator&(const Set<T> &other) const {
    Set<T> newSet;

    for (auto iter = cbegin(); iter != cend(); ++iter) {
        if (other.find(*iter) != other.cend()) {
            newSet.append(*iter);
        }
    }

    return newSet;
}

template <typename T>
Set<T> Set<T>::operator&(const T &data) const {
    Set<T> newSet;

    if (find(data) != cend()) {
        newSet.append(data);
    }

    return newSet;
}

template <typename T>
Set<T> &Set<T>::operator&=(const Set<T> &other) {
    Set<T> newSet = *this & other;

    clear();
    *this = newSet;

    return *this;
}

template <typename T>
Set<T> &Set<T>::operator&=(const T &data) {
    Set<T> newSet = *this & data;

    clear();
    *this = newSet;

    return *this;
}

template <typename T>
Set<T> Set<T>::operator|(const Set<T> &other) const {
    return *this + other;
}

template <typename T>
Set<T> Set<T>::operator|(const T &data) const {
    return *this + data;
}

template <typename T>
Set<T> &Set<T>::operator|=(const Set<T> &other) {
    *this += other;

    return *this;
}

template <typename T>
Set<T> &Set<T>::operator|=(const T &data) {
    *this += data;

    return *this;
}

template <typename T>
Set<T> Set<T>::combine(const Set<T> &other) const {
    return *this | other;
}

template <typename T>
Set<T> Set<T>::combine(const T &data) const {
    return *this | data;
}

template <typename T>
Set<T> Set<T>::difference(const Set<T> &other) const {
    return *this - other;
}

template <typename T>
Set<T> Set<T>::difference(const T &data) const {
    return *this - data;
}

template <typename T>
Set<T> Set<T>::operator-(const Set<T> &other) const {
    Set<T> newSet(*this);

    for (auto iter = other.cbegin(); iter != other.cend(); ++iter) {
        newSet.erase(*iter);
    }

    return newSet;
}

template <typename T>
Set<T> Set<T>::operator-(const T &data) const {
    Set<T> newSet(*this);
    newSet.erase(data);

    return newSet;
}

template <typename T>
Set<T> &Set<T>::operator-=(const Set<T> &other) {
    for (auto iter = other.cbegin(); iter != other.cend(); ++iter) {
        erase(*iter);
    }

    return *this;
}

template <typename T>
Set<T> &Set<T>::operator-=(const T &data) {
    erase(data);

    return *this;
}

template <typename T>
Set<T> Set<T>::symmetric_difference(const Set<T> &other) const {
    return *this ^ other;
}

template <typename T>
Set<T> Set<T>::symmetric_difference(const T &data) const {
    return *this ^ data;
}

template <typename T>
Set<T> Set<T>::operator^(const Set<T> &other) const {
    Set<T> newSet = *this | other;
    newSet -= *this & other;

    return newSet;
}

template <typename T>
Set<T> Set<T>::operator^(const T &data) const {
    Set<T> newSet = *this | data;
    newSet -= *this & data;

    return newSet;
}

template <typename T>
Set<T> &Set<T>::operator^=(const Set<T> &other) {
    auto intersectSetTmp = *this & other;
    *this |= other;
    *this -= intersectSetTmp;

    return *this;
}

template <typename T>
Set<T> &Set<T>::operator^=(const T &data) {
    auto intersectSetTmp = *this & data;
    *this |= data;
    *this -= intersectSetTmp;

    return *this;
}

template <typename T>
constIterator<T> Set<T>::erase(const T &value) {
    auto iterator = find(value);

    if (iterator != cend()) {
        return erase(iterator);
    }

    return cend();
}

template <typename T>
constIterator<T> Set<T>::erase(constIterator<T> rmIter) {
    if (empty()) {
        return cend();
    }

    if (!rmIter) {
        throw InvalidIteratorExeption(__TIME__, __FILE__, typeid(*this).name(),
                                      __FUNCTION__);
    }

    auto rmNodePointer = rmIter.getNodePointer();

    if (this->size == 1) {
        head->setNull();
        head = tail = nullptr;
        size--;
        return cend();
    }

    size--;

    if (rmNodePointer == head) {
        head = head->getNext();
        head->setPrevNull();
    }

    auto result = rmNodePointer->getNext();
    rmNodePointer->remove();

    return constIterator<T>(result);
}

template <typename T>
void Set<T>::clear() {
    if (empty()) return;
    auto next = head->getNext();

    for (; head; head = next) {
        next = head->getNext();
        head->setNull();
    }

    head = nullptr;
    tail = nullptr;

    size = 0;
}

template <typename T>
size_t Set<T>::getSize() {
    return size;
}

template <typename T>
Set<T> &Set<T>::operator=(const Set<T> &other) noexcept(false) {
    if (&other == this) {
        return *this;
    }

    clear();

    for (auto iter = other.cbegin(); iter != other.cend(); ++iter) {
        append(*iter);
    }

    return *this;
}

template <typename T>
Set<T> &Set<T>::operator=(Set<T> &&other) noexcept {
    size = other.size;
    head = other.head;
    tail = other.tail;

    other.clear();
}

template <typename T>
bool Set<T>::operator==(const Set<T> &other) const {
    if (size != other.size) {
        return false;
    }

    for (auto iter = other.cbegin(); iter != other.cend(); ++iter) {
        if (find(*iter) == cend()) {
            return false;
        }
    }

    return true;
}

template <typename T>
bool Set<T>::operator!=(const Set<T> &other) const {
    return !(*this == other);
}

template <typename T>
std::ostream &operator<<(std::ostream &os, Set<T> &set) {
    for (auto el = set.cbegin(); el != set.cend(); ++el) {
        os << *el << " ";
    }

    os << std::endl;
    return os;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const Set<T> &set) {
    for (auto el = set.cbegin(); el != set.cend(); ++el) {
        os << *el << " ";
    }

    os << std::endl;
    return os;
}
