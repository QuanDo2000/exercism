#include "robot_simulator.h"

robot_status_t robot_create(robot_direction_t direction, int x, int y) {
    robot_status_t robot = {
        .direction = direction,
        .position = (robot_position_t){.x = x, .y = y},
    };
    return robot;
}

void robot_move(robot_status_t *robot, const char *commands) {
    static int incx[] = {0, 1, 0, -1};
    static int incy[] = {1, 0, -1, 0};
    while ((*commands) != '\0') {
        char command = *commands;
        switch (command) {
            case 'R':
                robot->direction = (robot->direction + 1) % DIRECTION_MAX;
                break;
            case 'L':
                robot->direction = (robot->direction + 3) % DIRECTION_MAX;
                break;
            case 'A':
                robot->position = (robot_position_t){
                    .x = robot->position.x + incx[robot->direction],
                    .y = robot->position.y + incy[robot->direction],
                };
                break;
            default:
                break;
        }
        commands++;
    }
}