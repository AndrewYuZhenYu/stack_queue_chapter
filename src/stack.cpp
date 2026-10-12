#include "stack.h"

#include <stdexcept>
#include <utility>

FixedStack::FixedStack(std::size_t capacity) : data_(capacity) {
    if (capacity == 0) throw std::invalid_argument("capacity must be positive");
}
bool FixedStack::push(int value) {
    if (full()) return false;
    data_[size_++] = value;
    return true;
}
std::optional<int> FixedStack::pop() {
    if (empty()) return std::nullopt;
    return data_[--size_];
}
std::optional<int> FixedStack::top() const {
    if (empty()) return std::nullopt;
    return data_[size_ - 1];
}
bool FixedStack::empty() const { return size_ == 0; }
bool FixedStack::full() const { return size_ == data_.size(); }
std::size_t FixedStack::size() const { return size_; }
std::size_t FixedStack::capacity() const { return data_.size(); }
void FixedStack::clear() { size_ = 0; }
std::vector<int> FixedStack::bottom_to_top() const {
    return {data_.begin(), data_.begin() + static_cast<std::ptrdiff_t>(size_)};
}

void GrowingStack::push(int value) { data_.push_back(value); }
std::optional<int> GrowingStack::pop() {
    if (empty()) return std::nullopt;
    int value = data_.back();
    data_.pop_back();
    return value;
}
std::optional<int> GrowingStack::top() const {
    if (empty()) return std::nullopt;
    return data_.back();
}
bool GrowingStack::empty() const { return data_.empty(); }
std::size_t GrowingStack::size() const { return data_.size(); }
std::size_t GrowingStack::capacity() const { return data_.capacity(); }
void GrowingStack::clear() { data_.clear(); }
const std::vector<int>& GrowingStack::bottom_to_top() const { return data_; }

LinkedStack::Node::Node(int value, std::unique_ptr<Node> next)
    : value(value), next(std::move(next)) {}
LinkedStack::~LinkedStack() { clear(); }
void LinkedStack::push(int value) {
    head_ = std::make_unique<Node>(value, std::move(head_));
    ++size_;
}
std::optional<int> LinkedStack::pop() {
    if (empty()) return std::nullopt;
    int value = head_->value;
    auto old = std::move(head_);
    head_ = std::move(old->next);
    --size_;
    return value;
}
std::optional<int> LinkedStack::top() const {
    if (empty()) return std::nullopt;
    return head_->value;
}
bool LinkedStack::empty() const { return head_ == nullptr; }
std::size_t LinkedStack::size() const { return size_; }
void LinkedStack::clear() {
    while (head_) {
        auto old = std::move(head_);
        head_ = std::move(old->next);
    }
    size_ = 0;
}
