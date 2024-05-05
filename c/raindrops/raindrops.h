#ifndef RAINDROPS_H
#define RAINDROPS_H

typedef struct {
    int factor;
    const char* sound;
} sound_t;

void convert(char result[], int drops);

#endif
