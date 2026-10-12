#include "queue.h"

#include <stdexcept>
#include <utility>

LinearQueue::LinearQueue(std::size_t capacity) : data_(capacity) {
    if (capacity == 0) throw std::invalid_argument("capacity must be positive");
}
bool LinearQueue::enqueue(int value) {
    if (rear_ == data_.size()) return false;
    data_[rear_++] = value;
    return true;
}
std::optional<int> LinearQueue::dequeue() {
    if (front_ == rear_) return std::nullopt;
    return data_[front_++];
}
std::size_t LinearQueue::size() const { return rear_ - front_; }

CircularQueue::CircularQueue(std::size_t capacity) : data_(capacity + 1) {
    if (capacity == 0) throw std::invalid_argument("capacity must be positive");
}
bool CircularQueue::enqueue(int value) {
    if (full()) return false;
    data_[rear_] = value;
    rear_ = (rear_ + 1) % data_.size();
    return true;
}
std::optional<int> CircularQueue::dequeue() {
    if (empty()) return std::nullopt;
    int value = data_[front_];
    front_ = (front_ + 1) % data_.size();
    return value;
}
std::optional<int> CircularQueue::front() const {
    if (empty()) return std::nullopt;
    return data_[front_];
}
bool CircularQueue::empty() const { return front_ == rear_; }
bool CircularQueue::full() const { return (rear_ + 1) % data_.size() == front_; }
std::size_t CircularQueue::size() const {
    return (rear_ + data_.size() - front_) % data_.size();
}
std::size_t CircularQueue::capacity() const { return data_.size() - 1; }
void CircularQueue::clear() { front_ = rear_ = 0; }
std::vector<int> CircularQueue::front_to_rear() const {
    std::vector<int> result;
    for (std::size_t i = front_; i != rear_; i = (i + 1) % data_.size()) result.push_back(data_[i]);
    return result;
}

CountingQueue::CountingQueue(std::size_t capacity) : data_(capacity) {
    if (capacity == 0) throw std::invalid_argument("capacity must be positive");
}
bool CountingQueue::enqueue(int value) {
    if (full()) return false;
    data_[rear_] = value;
    rear_ = (rear_ + 1) % data_.size();
    ++size_;
    return true;
}
std::optional<int> CountingQueue::dequeue() {
    if (empty()) return std::nullopt;
    int value = data_[front_];
    front_ = (front_ + 1) % data_.size();
    --size_;
    return value;
}
bool CountingQueue::empty() const { return size_ == 0; }
bool CountingQueue::full() const { return size_ == data_.size(); }
std::size_t CountingQueue::size() const { return size_; }
std::size_t CountingQueue::capacity() const { return data_.size(); }
void CountingQueue::clear() { front_ = rear_ = size_ = 0; }
std::vector<int> CountingQueue::front_to_rear() const {
    std::vector<int> result;
    for (std::size_t i = 0; i < size_; ++i) result.push_back(data_[(front_ + i) % data_.size()]);
    return result;
}

LinkedQueue::Node::Node(int value) : value(value) {}
LinkedQueue::LinkedQueue() : dummy_(std::make_unique<Node>()), rear_(dummy_.get()) {}
LinkedQueue::~LinkedQueue() { clear(); }
void LinkedQueue::enqueue(int value) {
    rear_->next = std::make_unique<Node>(value);
    rear_ = rear_->next.get();
    ++size_;
}
std::optional<int> LinkedQueue::dequeue() {
    if (empty()) return std::nullopt;
    auto old = std::move(dummy_->next);
    int value = old->value;
    dummy_->next = std::move(old->next);
    if (!dummy_->next) rear_ = dummy_.get();
    --size_;
    return value;
}
std::optional<int> LinkedQueue::front() const {
    if (empty()) return std::nullopt;
    return dummy_->next->value;
}
bool LinkedQueue::empty() const { return dummy_->next == nullptr; }
std::size_t LinkedQueue::size() const { return size_; }
void LinkedQueue::clear() {
    while (dummy_->next) {
        auto old = std::move(dummy_->next);
        dummy_->next = std::move(old->next);
    }
    rear_ = dummy_.get();
    size_ = 0;
}
