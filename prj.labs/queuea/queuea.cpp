#include <queuea/queuea.hpp>

#include <cstddef>
#include <cstdint>

QueueA::QueueA():
	first_(0), last_(-1), capacity_(10), data_(new int64_t[10]) {}

QueueA::QueueA(const QueueA& src) {
	if (!src.is_empty()) {
		data_ = new int64_t[src.size()];
		memcpy(data_, src.data_ + src.first_, sizeof(int64_t) * src.size());
		
		first_ = 0;
		last_ = src.size() - 1;
		capacity_ = src.size();
	}
}

QueueA::~QueueA() {
	delete[] data_;
}

QueueA& QueueA::operator=(const QueueA& src) {
	if (!src.is_empty()) {
		int64_t* newdata_ = new int64_t[src.size()];
		memcpy(newdata_, src.data_ + src.first_, sizeof(int64_t) * src.size());
		delete[] data_;

		data_ = newdata_;
		first_ = 0;
		last_ = src.size() - 1;
		capacity_ = src.size();
	}
	return *this;
}

int64_t QueueA::size() const{
	return last_ - first_ + 1;
}

bool QueueA::is_empty() const {
	if (size()) {
		return 0;
	}
	return 1;
}

void QueueA::resize(const int64_t& newsize)
{
	if (size() >= newsize) {
		throw std::invalid_argument("New size is too small");
	}
	else {
		int64_t* newdata_ = new int64_t[newsize];
		int64_t sz = size();

		memcpy(newdata_, data_ + first_, sizeof(int64_t) * size());
		delete[] data_;

		data_ = newdata_;
		first_ = 0;
		last_ = first_ + sz-1;
		capacity_ = newsize;
	}
}

int64_t QueueA::pop() {
	if (!is_empty()) {
		return data_[first_++];
	}
	else {
		throw std::out_of_range("Queue is empty");
	}
}

void QueueA::push(int64_t newelement)
{
	if (last_+1 < capacity_) {
		data_[++last_] = newelement;
	}
	else {
		resize(size() * 2);
		data_[++last_] = newelement;
	}
}