#include "raindrops.h"

#include <stdio.h>
#include <string.h>

static const sound_t SOUNDS[] = {
    {3, "Pling"},
    {5, "Plang"},
    {7, "Plong"},
};

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

void convert(char result[], int drops) {
    for (size_t i = 0; i < ARRAY_SIZE(SOUNDS); i++) {
        if (drops % SOUNDS[i].factor == 0) {
            strcat(result, SOUNDS[i].sound);
        }
    }

    if (strlen(result) == 0) {
        sprintf(result, "%d", drops);
    }
}