#pragma once

namespace linked_list {
template <typename T>
class Node {
   public:
    T data;
    Node<T>* next;
    Node(T input, Node<T>* ptr = nullptr);
};

template <typename T>
class List {
   private:
    Node<T>* root;
    int _len;

   public:
    List();
    void push(T data);
    T pop();
    T shift();
    void unshift(T data);
    int count();
    bool erase(T data);
};
}  // namespace linked_list
