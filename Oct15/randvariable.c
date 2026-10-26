// By Nehan mohammad
// 26-October-26, Monday, question no: random_variable_generator

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    FILE *fp = fopen("random_vars.dat", "w");

    // Generate 20 random variables using inverse transform sampling
    for (int i = 0; i < 20; i++) {
        double u = (double)rand() / RAND_MAX;
        double x = cbrt(63.0 * u + 1.0);
        fprintf(fp, "%lf %lf\n",u , x);
    }

    fclose(fp);
    return 0;
}

