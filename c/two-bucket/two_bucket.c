#include "two_bucket.h"

static int next_idx(int idx) {
    return (idx + 1) % MAX_SIZE;
}

static bucket_state_t do_pour(bucket_state_t s, bucket_id_t id, bucket_liters_t b1_size, bucket_liters_t b2_size) {
    bucket_liters_t b_from = (id == BUCKET_ID_1) ? s.b1 : s.b2;
    bucket_liters_t b_to = (id == BUCKET_ID_1) ? s.b2 : s.b1;

    bucket_liters_t b_to_size = (id == BUCKET_ID_1) ? b2_size : b1_size;

    if (b_from == 0 || b_to == b_to_size) {
        return (bucket_state_t){s.b1, s.b2, s.move + 1};
    }

    if (b_from < (b_to_size - b_to)) {
        b_to += b_from;
        b_from = 0;
    } else if (b_from > (b_to_size - b_to)) {
        b_from -= b_to_size - b_to;
        b_to = b_to_size;
    } else {
        b_from = 0;
        b_to = b_to_size;
    }
    bucket_liters_t b1 = (id == BUCKET_ID_1) ? b_from : b_to;
    bucket_liters_t b2 = (id == BUCKET_ID_1) ? b_to : b_from;
    return (bucket_state_t){b1, b2, s.move + 1};
}

static bucket_state_t do_empty(bucket_state_t s, bucket_id_t id) {
    bucket_state_t s_nxt = (bucket_state_t){s.b1, s.b2, s.move + 1};
    if (id == BUCKET_ID_1) {
        s_nxt.b1 = 0;
    } else {
        s_nxt.b2 = 0;
    }
    return s_nxt;
}

static bucket_state_t do_fill(bucket_state_t s, bucket_id_t id, bucket_liters_t b1_size, bucket_liters_t b2_size) {
    bucket_state_t s_nxt = (bucket_state_t){s.b1, s.b2, s.move + 1};
    if (id == BUCKET_ID_1) {
        s_nxt.b1 = b1_size;
    } else {
        s_nxt.b2 = b2_size;
    }
    return s_nxt;
}

bucket_result_t measure(bucket_liters_t b1_size, bucket_liters_t b2_size, bucket_liters_t goal, bucket_id_t start) {
    bucket_result_t res = (bucket_result_t){false, 0, BUCKET_ID_1, 0};
    if ((goal > b1_size && goal > b2_size)) {
        return res;
    }

    char visited[b1_size + 1][b2_size + 1];
    for (bucket_liters_t i = 0; i <= b1_size; i++) {
        for (bucket_liters_t j = 0; j <= b2_size; j++) {
            visited[i][j] = 0;
        }
    }

    bucket_state_t queue[MAX_SIZE];
    int start_idx = 0;
    int end_idx = 0;
    if (start == BUCKET_ID_1) {
        visited[0][b2_size] = 1;
        queue[end_idx] = (bucket_state_t){b1_size, 0, 1};
    } else {
        visited[b1_size][0] = 1;
        queue[end_idx] = (bucket_state_t){0, b2_size, 1};
    }
    end_idx = next_idx(end_idx);

    while (end_idx != start_idx) {
        bucket_state_t s = queue[start_idx];
        start_idx = next_idx(start_idx);

        visited[s.b1][s.b2] = 1;
        if (s.b1 == goal || s.b2 == goal) {
            res.goal_bucket = (s.b1 == goal) ? BUCKET_ID_1 : BUCKET_ID_2;
            res.move_count = s.move;
            res.other_bucket_liters = (s.b1 == goal) ? s.b2 : s.b1;
            res.possible = true;
            return res;
        }

        for (bucket_id_t b_id = BUCKET_ID_1; b_id < NUM_BUCKETS; b_id++) {
            for (action_t a = POUR; a < NUM_ACTIONS; a++) {
                bucket_state_t s_nxt = (bucket_state_t){0, 0, 0};
                switch (a) {
                    case POUR:
                        s_nxt = do_pour(s, b_id, b1_size, b2_size);
                        break;
                    case EMPTY:
                        s_nxt = do_empty(s, b_id);
                        break;
                    case FILL:
                        s_nxt = do_fill(s, b_id, b1_size, b2_size);
                        break;
                    default:
                        break;
                }
                if (s_nxt.move == 0) continue;
                if (visited[s_nxt.b1][s_nxt.b2]) continue;
                queue[end_idx] = s_nxt;
                end_idx = next_idx(end_idx);
            }
        }
    }

    return res;
}