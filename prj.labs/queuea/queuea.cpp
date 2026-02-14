#include <queuea/queuea.hpp>

#include <cstddef>
#include <cstdint>

QueueA::QueueA(): last_(-1), capacity_(10),	data_(new int64_t[capacity_]) {}
