#include "binary_search_tree.h"

namespace binary_search_tree {
template <typename T>
binary_tree<T>::binary_tree(T data, binary_tree<T>* parent) {
    this->_data = data;
    this->_left = nullptr;
    this->_right = nullptr;
    this->_parent = parent;
}

template <typename T>
const T& binary_tree<T>::data() {
    return this->_data;
}
template <typename T>
const unique_ptr<binary_tree<T>>& binary_tree<T>::left() {
    return this->_left;
}
template <typename T>
const unique_ptr<binary_tree<T>>& binary_tree<T>::right() {
    return this->_right;
}

template <typename T>
void binary_tree<T>::insert(T data) {
    if (data > this->_data) {
        if (!this->right()) {
            this->_right = unique_ptr<binary_tree<T>>(new binary_tree<T>(data, this));
        } else {
            this->right()->insert(data);
        }
    } else if (data <= this->_data) {
        if (!this->left()) {
            this->_left = unique_ptr<binary_tree<T>>(new binary_tree<T>(data, this));
        } else {
            this->left()->insert(data);
        }
    }
}

template <typename T>
void binary_tree<T>::iterator::operator++() {
    if (!this->_current) return;
    if (this->_current->right()) {
        this->_current = this->_current->right().get();
        while (this->_current->left()) {
            this->_current = this->_current->left().get();
        }
    } else {
        while (this->_current->_parent && this->_current == this->_current->_parent->right().get()) {
            this->_current = this->_current->_parent;
        }
        this->_current = this->_current->_parent;
    }
}
template <typename T>
bool binary_tree<T>::iterator::operator!=(binary_tree<T>::iterator& it) {
    return this->_current != it._current;
}
template <typename T>
const T& binary_tree<T>::iterator::operator*() {
    return _current->data();
}

template <typename T>
typename binary_tree<T>::iterator binary_tree<T>::begin() {
    binary_tree<T>* p = this;
    while (p->left()) p = p->left().get();
    return {p};
}
template <typename T>
typename binary_tree<T>::iterator binary_tree<T>::end() {
    return {nullptr};
}
}  // namespace binary_search_tree

template class binary_search_tree::binary_tree<uint32_t>;
template class binary_search_tree::binary_tree<string>;