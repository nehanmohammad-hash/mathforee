// Code by Nehan Mohammad
// Gate 2025, Biotechnology, question 59.

#include <stdio.h>
#include <math.h>

int main() {
    // Given Parameters
	
    int power_limit = 10;
    
    // Calculate sequence iteratively
    double a = 0.0;
    int n = 0;
    double threshold = 1.0 / pow(2.0, power_limit);

    while (fabs(1.0 - a) >= threshold) {
        a = 0.5 * (1.0 + a);
        n++;
    }

    printf("Power limit exponent: %d,\n Threshold value: %e, \n Final sequence value of a_n: %.6f\n", power_limit, threshold, a);
    printf("Least value of n: %d\n", n);
    //printf("Absolute difference |1 - a_n|: %.8f\n", fabs(1.0 - a));

    return 0;
}

