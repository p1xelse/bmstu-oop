#pragma once

#include <memory>

template <typename T>
class SetNode {
 public:
    SetNode() = default;
    explicit SetNode(const T value);
    explicit SetNode(std::shared_ptr<SetNode<T>> &node);

    void set(const T &value);

    void setNext(const SetNode<T> &node);
    void setNext(std::shared_ptr<SetNode<T>> &node_ptr);
    void setNextNull();

    void setPrev(const SetNode<T> &node);
    void setPrev(std::shared_ptr<SetNode<T>> &node_ptr);
    void setPrevNull();

    void setNull();
    void remove();

    std::shared_ptr<SetNode<T>> getNext() const;
    std::shared_ptr<SetNode<T>> getPrev() const;

    const T &getValue() const;

    bool operator==(const std::shared_ptr<SetNode<T>> &node) const;
    bool operator!=(const std::shared_ptr<SetNode<T>> &node) const;

    ~SetNode() = default;

 private:
    T value;
    std::shared_ptr<SetNode<T>> next;
    std::shared_ptr<SetNode<T>> prev;
};

#include "SetNode.hpp"
