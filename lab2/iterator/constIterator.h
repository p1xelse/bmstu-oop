#pragma once

#include <iterator>
#include <memory>

#include "Set.h"
#include "SetNode.h"

template <typename T>
class Set;


template <typename T>
class constIterator : std::iterator<std::input_iterator_tag, T> {
 public:
    friend class Set<T>;

    constIterator();
    explicit constIterator(const std::shared_ptr<SetNode<T>>& node);
    constIterator(const constIterator<T>& iterator);
    ~constIterator() = default;

    explicit operator bool() const;

    constIterator<T>& operator++();
    constIterator<T> operator++(int);
    const T& operator*() const;
    const T* operator->() const;
    constIterator<T>& operator--();
    constIterator<T> operator--(int);

    constIterator<T>& operator=(const constIterator<T>& other) const;

    bool operator==(const constIterator<T>& other) const;
    bool operator!=(const constIterator<T>& other) const;

 protected:
    void next();
    void prev();
    SetNode<T>& getCurNode() const;
    std::shared_ptr<SetNode<T>> getNodePointer() const;

 private:
    std::weak_ptr<SetNode<T>> cur;
};

#include "constIterator.hpp"  // NOLINT