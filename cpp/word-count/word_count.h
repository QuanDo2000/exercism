#if !defined(WORD_COUNT_H)
#define WORD_COUNT_H

#include <map>
#include <string>

using namespace std;

namespace word_count {
map<string, int> words(string s);
}  // namespace word_count

#endif  // WORD_COUNT_H