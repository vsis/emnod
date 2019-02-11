#include <stdio.h>
#include <stdlib.h>
#include "util_test.c"
#include "emnod.h"
#include "emlink.h"

int test_create_emlink_factor_zero(){
    struct emnod * from = emnod_create(normal);
    struct emnod * to = emnod_create(normal);
    double factor = 0;
    struct emlink * emlink = emlink_create(from, to, factor);
    if (emlink && (emlink->from == from) && (emlink->to == to)
        && (emlink->factor == factor)){
        emnod_destroy(from);
        emnod_destroy(to);
        emlink_destroy(emlink);
        return 0;
    } else {
        return 1;
    }
}

int test_create_emlink_factor_pi(){
    struct emnod * from = emnod_create(normal);
    struct emnod * to = emnod_create(normal);
    double factor = 3.1415;
    struct emlink * emlink = emlink_create(from, to, factor);
    if (emlink && (emlink->from == from) && (emlink->to == to)
        && (emlink->factor == factor)){
        emnod_destroy(from);
        emnod_destroy(to);
        emlink_destroy(emlink);
        return 0;
    } else {
        return 1;
    }
}

int test_apply_state_factor_one(){
    struct emnod * from = emnod_create(normal);
    struct emnod * to = emnod_create(normal);
    double factor = 1;
    struct emlink * emlink = emlink_create(from, to, factor);
    if (emlink){
        from->state = 2;
        to->state = 1000;
        emlink_apply(emlink);
        if ((from->state == 2) && (to->state == 2)){
            emnod_destroy(from);
            emnod_destroy(to);
            emlink_destroy(emlink);
            return 0;
        }
    }
    return 1;
}

int test_apply_state_factor_zero(){
    struct emnod * from = emnod_create(normal);
    struct emnod * to = emnod_create(normal);
    double factor = 0;
    struct emlink * emlink = emlink_create(from, to, factor);
    if (emlink){
        from->state = 2;
        to->state = 1000;
        emlink_apply(emlink);
        if ((from->state == 2) && (to->state == 0)){
            emnod_destroy(from);
            emnod_destroy(to);
            emlink_destroy(emlink);
            return 0;
        }
    }
    return 1;
}

int test_apply_state_factor_minus_three(){
    struct emnod * from = emnod_create(normal);
    struct emnod * to = emnod_create(normal);
    double factor = -3;
    struct emlink * emlink = emlink_create(from, to, factor);
    if (emlink){
        from->state = 2;
        to->state = 1000;
        emlink_apply(emlink);
        if ((from->state == 2) && (to->state == -6)){
            emnod_destroy(from);
            emnod_destroy(to);
            emlink_destroy(emlink);
            return 0;
        }
    }
    return 1;
}

int main(){
    int failed_tests = 0;
    failed_tests += run_test(test_create_emlink_factor_zero, "create_emlink_factor_zero");
    failed_tests += run_test(test_create_emlink_factor_pi, "create_emlink_factor_pi");
    failed_tests += run_test(test_apply_state_factor_one, "apply_state_factor_one");
    failed_tests += run_test(test_apply_state_factor_zero, "apply_state_factor_zero");
    failed_tests += run_test(test_apply_state_factor_minus_three, "apply_state_factor_minus_three");
    return failed_tests;
}

