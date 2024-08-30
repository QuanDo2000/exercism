#if !defined(ANAGRAM_H)
#define ANAGRAM_H

#include <map>
#include <string>
#include <vector>

using namespace std;

namespace anagram {
class anagram {
   private:
    string _word;
    map<char, int> _count;
    map<char, int> count(string s);
    bool is_equal(string s);
    bool is_anagram(string s);

   public:
    anagram(string s);
    vector<string> matches(vector<string> words);
};
}  // namespace anagram

#endif  // ANAGRAM_H