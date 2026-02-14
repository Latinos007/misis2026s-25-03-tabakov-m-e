#include <stacka/stacka.hpp>


#include <cstring>
#include <stdexcept>
#include <utility>

StackA::StackA(const StackA& src)
	:last_(src.last_),
	data_(new int64_t[src.capacity_]),
	capacity_(src.capacity_)
{
	if (!src.is_empty()) {
		memcpy(data_, src.data_, (last_) * sizeof(*data_));
	}
}

StackA::~StackA() {
	delete[] data_;
}

StackA& StackA::operator=(const StackA& src) {
	if (this != &src) {
		int64_t* tmpdata_ = new int64_t[src.capacity_];
		memcpy(tmpdata_, src.data_, (src.last_) * sizeof(*src.data_));
		delete[] data_;
		data_ = tmpdata_;
		capacity_ = src.capacity_;
		last_ = src.last_;
	}
	return *this;
}

bool StackA::is_empty() const noexcept {
	if (last_ == 0) return true;
	return false;
}

void StackA::pop() noexcept {
	if (last_ > 0) {
		last_--;
	}
}

void StackA::push(const int64_t val) {
	if (last_ == capacity_) resize(int(capacity_ * 1.5));
	data_[last_] = val;
	last_++;
}

int64_t& StackA::top() {
	if (!is_empty()){
		int64_t& val = data_[last_-1];
		return val;
	}
	else {
		throw std::out_of_range("Stack is empty");
	}
}

int64_t StackA::top() const {
	if (!is_empty()) {
		int64_t val = data_[last_-1];
		return val;
	}
	else {
		throw std::out_of_range("Stack is empty");
	}
}

void StackA::clear() noexcept {
	last_ = 0;
}

void StackA::resize(const int newsize) {
	if (last_ > newsize){
		throw std::invalid_argument("New size is too small");
	}
	else {
		int64_t* tmpdata_ = new int64_t[newsize];
		memcpy(tmpdata_, data_, (last_) * sizeof(*data_));
		delete[] data_;
		data_ = tmpdata_;
		capacity_ = newsize;
	}
}