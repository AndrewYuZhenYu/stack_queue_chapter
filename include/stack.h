#pragma once

#include <cstddef>
#include <memory>
#include <optional>
#include <vector>

class FixedStack {
public:
    explicit FixedStack(std::size_t capacity);
    bool push(int value);
    std::optional<int> pop();
    std::optional<int> top() const;
    bool empty() const;
    bool full() const;
    std::size_t size() const;
    std::size_t capacity() const;
    void clear();
    std::vector<int> bottom_to_top() const;
private:
    std::vector<int> data_;
    std::size_t size_ = 0;
};

class GrowingStack {
public:
    void push(int value);
    std::optional<int> pop();
    std::optional<int> top() const;
    bool empty() const;
    std::size_t size() const;
    std::size_t capacity() const;
    void clear();
    const std::vector<int>& bottom_to_top() const;
private:
    std::vector<int> data_;
};

class LinkedStack {
    struct Node {
        int value;
        std::unique_ptr<Node> next;
        Node(int value, std::unique_ptr<Node> next);
    };
public:
    LinkedStack() = default;
    LinkedStack(const LinkedStack&) = delete;
    LinkedStack& operator=(const LinkedStack&) = delete;
    ~LinkedStack();
    void push(int value);
    std::optional<int> pop();
    std::optional<int> top() const;
    bool empty() const;
    std::size_t size() const;
    void clear();
private:
    std::unique_ptr<Node> head_;
    std::size_t size_ = 0;
};
