#include <stdio.h>

int main() {
    int a, b, c, output;

    printf("-------------------------\n");
    printf(" a   b   c   |   Output  \n");
    printf("-------------------------\n");

    // Loop through all 8 combinations of 3 variables (0 to 7 in binary)
    for (int i = 0; i < 8; i++) {
        a = (i >> 2) & 1; // Extract MSB
        b = (i >> 1) & 1; // Extract middle bit
        c = i & 1;        // Extract LSB

        // Boolean function: outputs 1 when at least two inputs are 1
        output = (a && b) || (b && c) || (c && a);

        printf(" %d   %d   %d   |     %d     \n", a, b, c, output);
    }
    printf("-------------------------\n");

    return 0;
}

