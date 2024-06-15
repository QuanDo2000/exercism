#include "bob.h"

static char is_upper(char ch) {
    return (ch >= 'A' && ch <= 'Z');
}

static char is_lower(char ch) {
    return (ch >= 'a' && ch < 'z');
}

static char is_char(char ch) {
    return is_upper(ch) || is_lower(ch);
}

static char whitespaces[] = "\n\t\r ";
static char is_whitespace(char ch) {
    for (int i = 0; whitespaces[i] != '\0'; i++) {
        if (ch == whitespaces[i]) return 1;
    }
    return 0;
}

static char specials[] = "!@#$%%^&*()[]{};:'\"?/.>,<-=_+`~";
static char is_special(char ch) {
    for (int i = 0; specials[i] != '\0'; i++) {
        if (ch == specials[i]) return 1;
    }
    return 0;
}

static char is_number(char ch) {
    return (ch >= '0' && ch <= '9');
}

static char check_question(char* greeting) {
    char* ptr = greeting;
    if (*ptr == '\0') return 0;
    while (*(ptr + 1) != '\0') ptr++;
    while (is_whitespace(*ptr) && ptr != greeting) ptr--;

    if (*ptr == '?') return 1;
    return 0;
}

static char check_yell(char* greeting) {
    char has_char = 0;
    for (; *greeting != '\0'; greeting++) {
        char ch = *greeting;
        if (is_char(ch)) has_char = 1;
        if (!(is_upper(ch) || is_whitespace(ch) ||
              is_special(ch) || is_number(ch))) return 0;
    }
    return has_char;
}

static char check_silence(char* greeting) {
    for (; *greeting != '\0'; greeting++) {
        char ch = *greeting;
        if (!is_whitespace(ch)) return 0;
    }
    return 1;
}

char* hey_bob(char* greeting) {
    if (check_question(greeting) && check_yell(greeting)) {
        return "Calm down, I know what I'm doing!";
    } else if (check_question(greeting)) {
        return "Sure.";
    } else if (check_yell(greeting)) {
        return "Whoa, chill out!";
    } else if (check_silence(greeting)) {
        return "Fine. Be that way!";
    }
    return "Whatever.";
}