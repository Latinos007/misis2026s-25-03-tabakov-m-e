#pragma once
#ifndef QUEUEL_QUEUEL_HPP
#define QUEUEL_QUEUEL_HPP

#include <cstddef>
#include <cstdint>

class QueueL {
public:
    QueueL() = default;

    QueueL(const QueueL& src);

    ~StackL() = default;

    StackL& operator=(const StackL& src);

    [[nodiscard]] bool is_empty() const noexcept;

    void pop() noexcept;

    void push(const int64_t val);

    [[nodiscard]] int64_t& top();

    [[nodiscard]] int64_t top() const;

    void clear() noexcept;

private:
    struct Node {
        int64_t val = int64_t();
        Node* next = nullptr;
    };

    Node* head_ = nullptr;
};

#endif