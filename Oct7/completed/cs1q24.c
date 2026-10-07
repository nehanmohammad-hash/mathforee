#include <stdio.h>

int X(int p, int q, int r) {
    return (p + q + r >= 2);
}

int main() {
    int optA = 1, optB = 1, optC = 1, optD = 1;

    for (int a = 0; a <= 1; a++) {
        for (int b = 0; b <= 1; b++) {
            for (int c = 0; c <= 1; c++) {
                
                // Check B & D (3 variables)
                if (X(a, b, X(a, b, c)) != X(a, b, c)) optB = 0;
                if (X(a, b, c) != X(a, X(a, b, c), X(a, c, c))) optD = 0;

                for (int d = 0; d <= 1; d++) {
                    
                    // Check C (4 variables)
                    if (X(a, b, X(a, c, d)) != (X(a, b, a) && X(c, d, c))) optC = 0;

                    for (int e = 0; e <= 1; e++) {
                        
                        // Check A (5 variables)
                        if (X(a, b, X(c, d, e)) != X(X(a, b, c), d, e)) optA = 0;
                    }
                }
            }
        }
    }

    printf("A (1=True, 0=False): %d\n", optA);
    printf("B (1=True, 0=False): %d\n", optB);
    printf("C (1=True, 0=False): %d\n", optC);
    printf("D (1=True, 0=False): %d\n", optD);

    return 0;
}

