// By Nehan mohammad
// 01-October-26, Thursday, question no: Q20

#include <stdio.h>

int main() {
    FILE *fp = fopen("plotpoint.txt", "w");
    long long T = 1;
    
    // Write initial condition
    fprintf(fp, "%d %lld\n", 0, T);
    
    // Compute recurrence values for n from 1 to 10
    for (int n = 1; n <= 20; n++) {
        T = 2 * T + n * (1LL << n);
        fprintf(fp, "%d %lld\n", n, T);
    }
    
    fclose(fp);
    return 0;
}

