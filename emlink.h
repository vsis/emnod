/*
 * Definition of a link between emnodes
 */

struct emlink{
    struct emnod * from;
    struct emnod * to;
    double factor;
};

/*
 * Create a link between emnodes
 */
struct emlink * emlink_create(struct emnod * from, struct emnod * to,
    double factor);

/*
 * Destroy link
 */
void emlink_destroy(struct emlink * emlink);

/*
 * Apply signal from origin emnod to destination emnod
 */
void emlink_apply(struct emlink * emlink);
