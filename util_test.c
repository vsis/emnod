/*
 * Utilities for testing
 */

void fail(char * name){
    printf("[FAIL]\t%s\n", name);
}

void success(char * name){
    printf("[ OK ]\t%s\n", name);
}

int run_test(int (test()), char * name){
    int result = test();
    if (result != 0){
        fail(name);
    } else {
        success(name);
    }
    return result;
}
