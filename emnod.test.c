#include <stdio.h>
#include <stdlib.h>
#include "util_test.c"
#include "emnod.h"

int test_create_normal_emnod(){
    struct emnod * normal_emnod = emnod_create(normal);
    if ((normal_emnod) && ( normal_emnod->type == normal)){
        emnod_destroy(normal_emnod);
        return 0;
    } else {
        return 1;
    }
}

int test_create_input_emnod(){
    struct emnod * input_emnod = emnod_create(input);
    if ((input_emnod) && (input_emnod->type == input)){
        emnod_destroy(input_emnod);
        return 0;
    } else {
        return 1;
    }
}

int test_create_output_emnod(){
    struct emnod * output_emnod = emnod_create(output);
    if ((output_emnod) && (output_emnod->type == output)){
        emnod_destroy(output_emnod);
        return 0;
    } else {
        return 1;
    }
}

int test_emnod_initial_state_zero(){
    struct emnod * normal_emnod = emnod_create(normal);
    if ((normal_emnod) && ( normal_emnod->state == 0)){
        emnod_destroy(normal_emnod);
        return 0;
    } else {
        return 1;
    }
}

int main(){
    int failed_tests = 0;
    failed_tests += run_test(test_create_normal_emnod, "create_normal_emnod");
    failed_tests += run_test(test_create_input_emnod, "create_input_emnod");
    failed_tests += run_test(test_create_output_emnod, "create_output_emnod");
    failed_tests += run_test(test_emnod_initial_state_zero, "emnod_initial_state_zero");
    return failed_tests;
}
