#include "kindergarten_garden.h"

plants_t plants(const char* diagram, const char* student) {
    int student_idx = student[0] - 'A';
    int len = 0;
    while (diagram[len++] != '\n');

    return (plants_t){
        .plants = {
            diagram[student_idx * 2],
            diagram[student_idx * 2 + 1],
            diagram[len + student_idx * 2],
            diagram[len + student_idx * 2 + 1],
        }};
}