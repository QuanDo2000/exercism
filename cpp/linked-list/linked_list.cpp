#include "linked_list.h"

#include <stdexcept>

namespace linked_list {
template <typename T>
Node<T>::Node(T input, Node<T>* ptr) {
    data = input;
    next = ptr;
}

template <typename T>
List<T>::List() {
    root = nullptr;
    _len = 0;
}

template <typename T>
void List<T>::push(T data) {
    if (root == nullptr) {
        root = new Node<T>(data);
        _len++;
        return;
    }

    Node<T>* curr = root;
    Node<T>* next = root->next;
    while (next != nullptr) {
        curr = next;
        next = curr->next;
    }

    Node<T>* new_node = new Node<T>(data);
    curr->next = new_node;
    _len++;
}

template <typename T>
T List<T>::pop() {
    if (root == nullptr) {
        throw std::runtime_error("no item in list");
    }

    Node<T>* prev = root;
    Node<T>* curr = root;
    Node<T>* next = root->next;
    while (next != nullptr) {
        prev = curr;
        curr = next;
        next = curr->next;
    }

    prev->next = nullptr;
    T result = curr->data;
    delete curr;
    _len--;
    if (_len == 0) root = nullptr;
    return result;
}

template <typename T>
T List<T>::shift() {
    if (root == nullptr) {
        throw std::runtime_error("no item in list");
    }

    Node<T>* next = root->next;
    T result = root->data;
    delete root;
    root = next;
    _len--;
    if (_len == 0) root = nullptr;
    return result;
}

template <typename T>
void List<T>::unshift(T data) {
    if (root == nullptr) {
        root = new Node<T>(data);
        _len++;
        return;
    }

    Node<T>* new_node = new Node<T>(data, root);
    root = new_node;
    _len++;
}

template <typename T>
int List<T>::count() {
    return _len;
}

template <typename T>
bool List<T>::erase(T data) {
    if (root == nullptr) throw std::runtime_error("no item in list");

    Node<T>* prev = root;
    Node<T>* curr = root;
    Node<T>* next = root->next;
    while (next != nullptr && curr->data != data) {
        prev = curr;
        curr = next;
        next = curr->next;
    }
    if (curr->data != data) return false;

    if (prev == curr) {
        root = next;
    } else {
        prev->next = next;
    }

    delete curr;
    _len--;
    return true;
}
}  // namespace linked_list

template class linked_list::Node<int>;
template class linked_list::List<int>;