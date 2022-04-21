#pragma once

#include "BaseContainer.h"
#include "SetNode.h"
#include "constIterator.h"
#include "exeptions.h"

template <typename T>
class Set : public BaseContainer {
 public:
    Set() = default;
    Set(const Set<T> &list) noexcept(false);
    Set(Set<T> &&list) noexcept;
    Set(std::initializer_list<T> elems);

    ~Set() override;

    // Modifiers
    bool append(const T &value) noexcept(false);
    bool append(T &&value) noexcept(false);
    void append(std::initializer_list<T> initList) noexcept(false);
    void append(T *initArr, size_t len) noexcept(false);

    Set<T> update(const T &value) noexcept(false);
    Set<T> update(T &&value) noexcept(false);
    Set<T> update(std::initializer_list<T> initList) noexcept(false);
    Set<T> update(T *initArr, size_t len) noexcept(false);

    Set<T> operator+(const Set<T> &other);
    Set<T> operator+(const T &data);
    Set<T> &operator+=(const Set<T> &other);
    Set<T> &operator+=(const T &data);

    Set<T> intersect(const Set<T> &other);
    Set<T> intersect(const T &data);

    Set<T> operator&(const Set<T> &other);
    Set<T> operator&(const T &data);
    Set<T> &operator&=(const Set<T> &other);
    Set<T> &operator&=(const T &data);

    Set<T> combine(const Set<T> &other);
    Set<T> combine(const T &data);

    Set<T> operator|(const Set<T> &other);
    Set<T> operator|(const T &data);
    Set<T> &operator|=(const Set<T> &other);
    Set<T> &operator|=(const T &data);

    Set<T> difference(const Set<T> &other);
    Set<T> difference(const T &data);

    Set<T> operator-(const Set<T> &other);
    Set<T> operator-(const T &data);
    Set<T> &operator-=(const Set<T> &other);
    Set<T> &operator-=(const T &data);

    Set<T> symmetric_difference(const Set<T> &other);
    Set<T> symmetric_difference(const T &data);

    Set<T> operator^(const Set<T> &other);
    Set<T> operator^(const T &data);
    Set<T> &operator^=(const Set<T> &other);
    Set<T> &operator^=(const T &data);

    constIterator<T> erase(const T &value);
    constIterator<T> erase(constIterator<T> pos);

    void clear() override;

    // Capacity
    size_t getSize();

    // Lookup
    constIterator<T> find(const T &val) const;

    // Non-member
    Set<T> &operator=(const Set<T> &other) noexcept(false);
    Set<T> &operator=(Set<T> &&other) noexcept;

    bool operator==(const Set<T> &other) const;
    bool operator!=(const Set<T> &other) const;

    // Iterators
    constIterator<T> cbegin() const;
    constIterator<T> cend() const;

 protected:
    bool append(const std::shared_ptr<SetNode<T>> &node) noexcept(false);

 private:
    std::shared_ptr<SetNode<T>> head;
    std::shared_ptr<SetNode<T>> tail;
};

#include "Set.hpp"
