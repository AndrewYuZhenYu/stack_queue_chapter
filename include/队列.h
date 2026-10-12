#pragma once

#include <cstddef>
#include <memory>
#include <optional>
#include <vector>

// 非循环队列：只用于说明假溢出。
class LinearQueue {
public:
    explicit LinearQueue(std::size_t capacity);
    bool enqueue(int value);
    std::optional<int> dequeue();
    std::size_t size() const;
private:
    std::vector<int> data_;
    std::size_t front_ = 0;
    std::size_t rear_ = 0;
};

// 留一个空槽区分空与满；对外容量不包含这个空槽。
class CircularQueue {
public:
    explicit CircularQueue(std::size_t capacity);
    bool enqueue(int value);
    std::optional<int> dequeue();
    std::optional<int> front() const;
    bool empty() const;
    bool full() const;
    std::size_t size() const;
    std::size_t capacity() const;
    void clear();
    std::vector<int> front_to_rear() const;
private:
    std::vector<int> data_;
    std::size_t front_ = 0;
    std::size_t rear_ = 0;
};

// 用长度计数区分空与满，数组每个槽都可存元素。
class CountingQueue {
public:
    explicit CountingQueue(std::size_t capacity);
    bool enqueue(int value);
    std::optional<int> dequeue();
    bool empty() const;
    bool full() const;
    std::size_t size() const;
    std::size_t capacity() const;
    void clear();
    std::vector<int> front_to_rear() const;
private:
    std::vector<int> data_;
    std::size_t front_ = 0;
    std::size_t rear_ = 0;
    std::size_t size_ = 0;
};

class LinkedQueue {
    struct Node {
        int value;
        std::unique_ptr<Node> next;
        explicit Node(int value = 0);
    };
public:
    LinkedQueue();
    LinkedQueue(const LinkedQueue&) = delete;
    LinkedQueue& operator=(const LinkedQueue&) = delete;
    ~LinkedQueue();
    void enqueue(int value);
    std::optional<int> dequeue();
    std::optional<int> front() const;
    bool empty() const;
    std::size_t size() const;
    void clear();
private:
    std::unique_ptr<Node> dummy_;
    Node* rear_;
    std::size_t size_ = 0;
};
