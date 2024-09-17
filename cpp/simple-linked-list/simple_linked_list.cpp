#include "simple_linked_list.h"

#include <stdexcept>

namespace simple_linked_list {

std::size_t List::size() const {
    return current_size;
}

void List::push(int entry) {
    if (head == nullptr) {
        head = new Element(entry);
        current_size++;
        return;
    }

    Element* new_node = new Element(entry);
    new_node->next = head;
    head = new_node;
    current_size++;
    return;
}

int List::pop() {
    if (head == nullptr)
        throw std::runtime_error("list has no element");

    Element* to_delete = head;
    int result = to_delete->data;
    head = head->next;
    delete to_delete;
    current_size--;
    return result;
}

void List::reverse() {
    if (head == nullptr) return;

    Element* prev = nullptr;
    Element* curr = head;
    while (curr != nullptr) {
        Element* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

List::~List() {
    Element* curr = head;
    while (curr != nullptr) {
        Element* next = curr->next;
        delete curr;
        curr = next;
    }
    current_size = 0;
}

}  // namespace simple_linked_list
