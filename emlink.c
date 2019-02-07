#include <stdlib.h>
#include "emnod.h"
#include "emlink.h"

struct emlink * emlink_create(struct emnod * from, struct emnod * to,
    double factor){
    struct emlink * new_emlink = (struct emlink *)malloc(sizeof(struct emlink));
    if (new_emlink){
        new_emlink->from = from;
        new_emlink->to = to;
        new_emlink->factor = factor;
        return new_emlink;
    } else {
        return NULL;
    }
}

void emlink_destroy(struct emlink * emlink){
    free(emlink);
}

void emlink_apply(struct emlink * emlink){
    double link_state = emlink->from->state;
    link_state *= emlink->factor;
    emlink->to->state = link_state;
}

