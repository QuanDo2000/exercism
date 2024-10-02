#include "pig_latin.h"

namespace pig_latin {
bool is_vowel(char ch) {
    string vowels = "aeiou";
    return isalpha(ch) && vowels.find(tolower(ch)) != string::npos;
}

bool is_consonant(char ch) {
    return isalpha(ch) && !is_vowel(ch);
}

size_t find_first_vowel(string word) {
    for (size_t i = 0; i < word.size(); i++) {
        if (is_vowel(word[i])) return i;
    }
    return word.size();
}

bool rule_1(string word) {
    string prefix = word.substr(0, 2);
    return word.size() > 0 &&
           (is_vowel(word[0]) || prefix == "xr" || prefix == "yt");
}

bool rule_2(string word) {
    return word.size() > 0 && (is_consonant(word[0]));
}

bool rule_3(string word) {
    size_t pos = word.find("qu");
    if (pos == string::npos) return false;
    for (size_t i = 0; i < pos; i++) {
        if (!is_consonant(word[i])) return false;
    }
    return true;
}

bool rule_4(string word) {
    size_t pos = word.find("y");
    if (pos == string::npos || pos == 0) return false;
    for (size_t i = 0; i < pos; i++) {
        if (!is_consonant(word[i])) return false;
    }
    return true;
}

string translate_word(string word) {
    if (rule_1(word)) {
        return word + "ay";
    } else if (rule_3(word)) {
        size_t pos = word.find("qu");
        return word.substr(pos + 2) + word.substr(0, pos + 2) + "ay";
    } else if (rule_4(word)) {
        size_t pos = word.find("y");
        return word.substr(pos) + word.substr(0, pos) + "ay";
    } else if (rule_2(word)) {
        size_t pos = find_first_vowel(word);
        return word.substr(pos) + word.substr(0, pos) + "ay";
    }
    return word;
}

string translate(string text) {
    string ans;
    size_t pos = 0;
    string token;
    while ((pos = text.find(' ')) != string::npos) {
        token = text.substr(0, pos);
        ans += translate_word(token);
        ans += " ";
        text.erase(0, pos + 1);
    }
    ans += translate_word(text);

    return ans;
}
}  // namespace pig_latin
