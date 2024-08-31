#if !defined(BINARY_SEARCH_TREE_H)
#define BINARY_SEARCH_TREE_H

#include <iterator>
#include <memory>
#include <string>

using namespace std;

namespace binary_search_tree {
template <typename T>
class binary_tree {
   private:
    T _data;
    binary_tree<T>* _parent;
    unique_ptr<binary_tree<T>> _left;
    unique_ptr<binary_tree<T>> _right;

   public:
    binary_tree(T data, binary_tree<T>* parent = nullptr);
    const T& data();
    const unique_ptr<binary_tree<T>>& left();
    const unique_ptr<binary_tree<T>>& right();
    void insert(T data);

    struct iterator {
        binary_tree<T>* _current;
        void operator++();
        bool operator!=(iterator& it);
        const T& operator*();
    };
    iterator begin();
    iterator end();
};
}  // namespace binary_search_tree

#endif  // BINARY_SEARCH_TREE_H