#include "grade_school.h"

#include <stdlib.h>
#include <string.h>

void init_roster(roster_t* roster) {
    roster->count = 0;
    return;
}

char add_student(roster_t* roster, const char* student, const uint8_t grade) {
    if (roster->count >= MAX_STUDENTS) return 0;

    for (size_t i = 0; i < roster->count; i++) {
        student_t curr = roster->students[i];
        if (strcmp(curr.name, student) == 0) return 0;
    }

    student_t new_student;
    new_student.grade = grade;
    strncpy(new_student.name, student, MAX_NAME_LENGTH);

    for (size_t i = 0; i < roster->count; i++) {
        student_t curr = roster->students[i];
        if ((strcmp(new_student.name, curr.name) < 0 && new_student.grade == curr.grade) || (new_student.grade < curr.grade)) {
            roster->students[i] = new_student;
            new_student = curr;
        }
    }
    roster->students[roster->count++] = new_student;

    return 1;
}

roster_t get_grade(roster_t* roster, const uint8_t grade) {
    roster_t grade_roster;
    init_roster(&grade_roster);

    for (size_t i = 0; i < roster->count; i++) {
        student_t curr = roster->students[i];
        if (curr.grade == grade) add_student(&grade_roster, curr.name, curr.grade);
    }
    return grade_roster;
}