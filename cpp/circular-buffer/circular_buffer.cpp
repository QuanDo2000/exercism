#include "circular_buffer.h"

#include <stdexcept>

namespace circular_buffer {
template <typename T>
circular_buffer<T>::circular_buffer(int size) {
    this->ptr = new T[size];
    this->_size = size;
    this->_len = 0;
    this->_start = 0;
}

template <typename T>
circular_buffer<T>::~circular_buffer() {
    delete[] this->ptr;
}

template <typename T>
T circular_buffer<T>::read() {
    if (this->_len == 0) throw std::domain_error("no value in buffer");
    T value = this->ptr[this->_start++];
    this->_start %= this->_size;
    this->_len--;
    return value;
}

template <typename T>
void circular_buffer<T>::write(T value) {
    if (this->_size == this->_len) throw std::domain_error("can't write to full buffer");
    int new_start = (this->_start + (this->_len++)) % this->_size;
    this->ptr[new_start] = value;
    return;
}

template <typename T>
void circular_buffer<T>::overwrite(T value) {
    if (this->_size == this->_len) {
        this->_start++;
        this->_start %= this->_size;
        this->_len--;
    }
    return write(value);
}

template <typename T>
void circular_buffer<T>::clear() {
    this->_start = 0;
    this->_len = 0;
}
}  // namespace circular_buffer

template class circular_buffer::circular_buffer<int>;
template class circular_buffer::circular_buffer<std::string>;