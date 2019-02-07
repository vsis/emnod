#include <stdlib.h>
#include "emnod.h"


struct emnod * emnod_create(enum emnod_type type){
    struct emnod * new_emnod;
    new_emnod = (struct emnod *) malloc(sizeof(struct emnod));
    if (new_emnod){
        new_emnod->type = type;
        new_emnod->state = 0;
        return new_emnod;
    } else {
        return NULL;
    }
}

void emnod_destroy(struct emnod * emnod){
    free(emnod);
}

