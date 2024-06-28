#ifndef TWO_BUCKET_H
#define TWO_BUCKET_H

#include <limits.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef enum { BUCKET_ID_1,
               BUCKET_ID_2,
               NUM_BUCKETS } bucket_id_t;

typedef enum { POUR,
               EMPTY,
               FILL,
               NUM_ACTIONS } action_t;

typedef unsigned int bucket_liters_t;

typedef struct {
    bool possible;
    int move_count;
    bucket_id_t goal_bucket;
    bucket_liters_t other_bucket_liters;
} bucket_result_t;

typedef struct {
    bucket_liters_t b1;
    bucket_liters_t b2;
    int move;
} bucket_state_t;

bucket_result_t measure(bucket_liters_t bucket_1_size,
                        bucket_liters_t bucket_2_size,
                        bucket_liters_t goal_volume, bucket_id_t start_bucket);

#endif
