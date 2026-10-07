#include <stdio.h>

int main() {
    int x = 2; // Binary: 10
    int y = 3; // Binary: 11

    // --- Difference 1: Numerical Output ---
    int result_bitwise = (x & y);   // Bitwise AND
    int result_logical = (x && y);  // Logical AND

    printf("x = %d, y = %d\n", x, y);
    printf("x & y  (Bitwise) = %d\n", result_bitwise); // Outputs 2 (binary 10)
    printf("x && y (Logical) = %d\n", result_logical); // Outputs 1 (true)

    // --- Difference 2: Short-Circuit Evaluation (Safety) ---
    int *ptr = NULL;

    // SAFE: Using &&
    // Because ptr is NULL, the left side is false. 
    // Due to short-circuiting, C stops evaluating and NEVER checks *ptr.
    if (ptr != NULL && *ptr == 10) {
        printf("This won't print, but it won't crash either.\n");
    } else {
        printf("Safe check passed using &&!\n");
    }

    /* 
       UNSAFE: If you replace && with & like this:
       if (ptr != NULL & *ptr == 10) { ... }
       
       C will evaluate BOTH sides. It will try to dereference a NULL pointer (*ptr),
       resulting in a Segmentation Fault (Crash).
    */

    return 0;
}

