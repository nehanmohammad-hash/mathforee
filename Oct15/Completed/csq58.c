// By Nehan mohammad
// 15-October-26, Thursday, question no: probability_dat_generator

#include <stdio.h>

int main() {
    FILE *fp = fopen("prob_data.dat", "w");
    double C = 1.0 / 21.0;

    // Write x and P(x) values to file for 1 <= x <= 4
    for (double x = 1.0; x <= 4.0; x += 0.1) {
        fprintf(fp, "%lf %lf\n", x, C * x * x);
    }

    fclose(fp);
    return 0;
}

