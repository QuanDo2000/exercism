#include "anagram.h"

#include <cctype>

namespace anagram {
map<char, int> anagram::count(string s) {
    map<char, int> ans;
    for (char ch : s) {
        if (isalpha(ch)) ans[tolower(ch)]++;
    }
    return ans;
}

bool anagram::is_equal(string s) {
    if (s.size() != this->_word.size()) return false;
    for (size_t i = 0; i < s.size(); i++) {
        if (tolower(s[i]) != tolower(this->_word[i])) return false;
    }
    return true;
}

bool anagram::is_anagram(string s) {
    return count(s) == this->_count && !is_equal(s);
}

anagram::anagram(string s) {
    this->_word = s;
    this->_count = count(s);
}

vector<string> anagram::matches(vector<string> words) {
    vector<string> ans;
    for (string word : words) {
        if (is_anagram(word)) ans.emplace_back(word);
    }
    return ans;
}
}  // namespace anagram
