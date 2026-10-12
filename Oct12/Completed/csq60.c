// By Nehan mohammad
// 12-October-26, Monday, question no: q60_state_transition

#include <stdio.h>
#include <stdlib.h>
#include "libs/listgen.h"

int main() {
    // Iterate through all 16 possible states for Q0 Q1 Q2 Q3
    for (int i = 0; i < 16; i++) {
        int q0 = (i >> 3) & 1;
        int q1 = (i >> 2) & 1;
        int q2 = (i >> 1) & 1;
        int q3 = i & 1;
        
        // Compute next state values based on D flip-flop input logic
        int nq0 = !q3;
        int nq1 = q0;
        int nq2 = q1;
        int nq3 = q2;
        
        printf("State: %d %d %d %d -> Next: %d %d %d %d\n", q0, q1, q2, q3, nq0, nq1, nq2, nq3);
    }
    
    return 0;
}

