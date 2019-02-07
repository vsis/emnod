/*
 * Definition of an emnod.
 */

struct emnod {
    double state;
    unsigned char type;
};


/*
 * Definition of emnod types
 */
enum emnod_type {normal, input, output, log};

/*
 * Function to create emnod
 */
struct emnod * emnod_create(enum emnod_type type);

/*
 * Function to destroy emnod
 */
void emnod_destroy(struct emnod * emnod);
