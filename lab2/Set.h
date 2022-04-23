#pragma once

#include "BaseContainer.h"
#include "SetNode.h"
#include "constIterator.h"
#include "exceptions.h"

template <typename T>
class Set : public BaseContainer {
 public:
    Set() = default;
    Set(const Set<T> &list);
    Set(Set<T> &&list) noexcept;
    Set(std::initializer_list<T> elems);

    template <typename IterType>
    Set(IterType &begin, IterType &end);

    Set(T *arr, size_t len);

    ~Set() override;

    // Modifiers

    Set<T> update(const T &value);
    Set<T> update(T &&value);
    Set<T> update(std::initializer_list<T> initList);
    Set<T> update(T *initArr, size_t len);

    Set<T> operator+(const Set<T> &other) const;
    Set<T> operator+(const T &data) const;
    Set<T> &operator+=(const Set<T> &other);
    Set<T> &operator+=(const T &data);

    bool append(const T &value);
    bool append(T &&value);
    void append(std::initializer_list<T> initList);
    void append(T *initArr, size_t len);

    Set<T> intersect(const Set<T> &other) const;
    Set<T> intersect(const T &data) const;

    Set<T> operator&(const Set<T> &other) const;
    Set<T> operator&(const T &data) const;
    Set<T> &operator&=(const Set<T> &other);
    Set<T> &operator&=(const T &data);

    Set<T> combine(const Set<T> &other) const;
    Set<T> combine(const T &data) const;

    Set<T> operator|(const Set<T> &other) const;
    Set<T> operator|(const T &data) const;
    Set<T> &operator|=(const Set<T> &other);
    Set<T> &operator|=(const T &data);

    Set<T> difference(const Set<T> &other) const;
    Set<T> difference(const T &data) const;

    Set<T> operator-(const Set<T> &other) const;
    Set<T> operator-(const T &data) const;
    Set<T> &operator-=(const Set<T> &other);
    Set<T> &operator-=(const T &data);

    Set<T> symmetric_difference(const Set<T> &other) const;
    Set<T> symmetric_difference(const T &data) const;

    Set<T> operator^(const Set<T> &other) const;
    Set<T> operator^(const T &data) const;
    Set<T> &operator^=(const Set<T> &other);
    Set<T> &operator^=(const T &data);

    constIterator<T> erase(const T &value);

    void clear() override;

    // Capacity
    size_t getSize();

    // Lookup
    bool belong(const T &val) const;

    // Non-member
    Set<T> &operator=(const Set<T> &other);
    Set<T> &operator=(Set<T> &&other) noexcept;
    Set<T> &operator=(std::initializer_list<T> initList);

    bool operator==(const Set<T> &other) const;
    bool operator!=(const Set<T> &other) const;
    bool operator<(const Set<T> &other) const;
    bool operator>(const Set<T> &other) const;
    bool operator<=(const Set<T> &other) const;
    bool operator>=(const Set<T> &other) const;

    // Iterators
    constIterator<T> begin() const;
    constIterator<T> end() const;

 protected:
    bool append(const std::shared_ptr<SetNode<T>> &node);
    constIterator<T> getIter(const T &val) const;
    constIterator<T> erase(constIterator<T> pos);

 private:
    std::shared_ptr<SetNode<T>> head;
    std::shared_ptr<SetNode<T>> tail;
};

#include "Set.hpp"
