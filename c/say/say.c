#include "say.h"

#include <stdlib.h>
#include <string.h>

static char* ONES[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
static char* TENS[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
static char* TEENS[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
static char* THOUSANDS[] = {"thousand", "million", "billion"};

static void print_tens(int tens, char* ans) {
    if (tens > 0) {
        if (strlen(ans) > 0) strcat(ans, " ");
        strcat(ans, TENS[tens]);
    }
}

static void print_ones(int ones, char* ans) {
    if (ones > 0) strcat(ans, ONES[ones]);
}

static void print_chunk(int chunk, char* ans) {
    if (chunk >= 100) {
        int hundred = chunk / 100;
        print_ones(hundred, ans);
        strcat(ans, " hundred");
    }

    if (chunk < 10 || chunk >= 20) {
        int tens = (chunk / 10) % 10;
        int ones = chunk % 10;
        print_tens(tens, ans);
        if (tens != 0 && ones != 0) strcat(ans, "-");
        print_ones(ones, ans);
    } else {
        strcat(ans, TEENS[chunk - 10]);
    }
}

static void print_thousandth(int th_idx, char* ans) {
    if (th_idx > 0) {
        strcat(ans, " ");
        strcat(ans, THOUSANDS[th_idx - 1]);
    }
}

static void concat_start(char* str1, char* str2) {
    char* tmp = calloc(strlen(str1) + 1, sizeof(char));

    strcpy(tmp, str1);
    strcpy(str1, str2);
    if (strlen(tmp) > 0) strcat(str1, " ");
    strcat(str1, tmp);

    free(tmp);
}

int say(int64_t input, char** ans) {
    if (input < 0 || input > 999999999999) return -1;

    (*ans) = calloc(MAX_LEN, sizeof(char));

    if (input == 0) {
        strcat(*ans, "zero");
        return 0;
    }

    int th_idx = 0;
    while (input > 0) {
        char* chunk_buf = calloc(MAX_LEN, sizeof(char));

        int chunk = input % 1000;
        print_chunk(chunk, chunk_buf);
        if (chunk != 0) print_thousandth(th_idx, chunk_buf);
        input /= 1000;

        concat_start(*ans, chunk_buf);
        free(chunk_buf);
        th_idx++;
    }

    return 0;
}