#pragma once

#include <functional>
#include <vector>

using namespace std;

namespace list_ops {
template <typename T>
void append(vector<T>& left, vector<T>& right) {
    for (auto item : right) {
        left.emplace_back(item);
    }
    return;
}

template <typename T>
vector<T> concat(vector<vector<T>> input) {
    vector<T> ans;
    for (auto v : input) {
        for (auto item : v) {
            ans.emplace_back(item);
        }
    }
    return ans;
}
template <typename T, typename Func>
vector<T> filter(vector<T> input, Func f) {
    vector<T> ans;
    for (auto item : input) {
        if (f(item)) ans.emplace_back(item);
    }
    return ans;
}

template <typename T>
size_t length(vector<T> input) {
    return input.size();
}

template <typename T, typename Func>
vector<T> map(vector<T> input, Func f) {
    vector<T> ans;
    for (auto item : input) {
        ans.emplace_back(f(item));
    }
    return ans;
}

template <typename T, typename Func>
T foldl(vector<T> input, T acc, Func f) {
    for (auto item : input) {
        acc = f(acc, item);
    }
    return acc;
}

template <typename T, typename Func>
T foldr(vector<T> input, T acc, Func f) {
    for (int i = input.size() - 1; i >= 0; i--) {
        acc = f(acc, input[i]);
    }
    return acc;
}

template <typename T>
vector<T> reverse(vector<T>& input) {
    std::reverse(input.begin(), input.end());
    return input;
}
}  // namespace list_ops
