// By Nehan mohammad
// 12-October-26, Monday, question no: fsm_minimization

#include <stdio.h>
#include <stdlib.h>
//#include "libs/listgen.h"

int main() {
    // State transition and output tables representation
    // States: 0->A, 1->B, 2->C, 3->D, 4->E, 5->F, 6->G, 7->H
    int next_state[8][2] = {
        {5, 1}, // A: X=0 -> F(5), X=1 -> B(1)
        {3, 2}, // B: X=0 -> D(3), X=1 -> C(2)
        {5, 4}, // C: X=0 -> F(5), X=1 -> E(4)
        {6, 0}, // D: X=0 -> G(6), X=1 -> A(0)
        {3, 2}, // E: X=0 -> D(3), X=1 -> C(2)
        {5, 1}, // F: X=0 -> F(5), X=1 -> B(1)
        {6, 7}, // G: X=0 -> G(6), X=1 -> H(7)
        {6, 0}  // H: X=0 -> G(6), X=1 -> A(0)
    };

    int output[8][2] = {
        {0, 0}, // A
        {0, 0}, // B
        {0, 0}, // C
        {1, 0}, // D
        {0, 0}, // E
        {1, 1}, // F
        {0, 1}, // G
        {1, 0}  // H
    };

    // Partition refinement to find equivalent states
    int p[8];
    for(int i = 0; i < 8; i++) {
        p[i] = output[i][0] * 2 + output[i][1]; // Initial partition based on outputs
    }

    int changed = 1;
    while(changed) {
        changed = 0;
        int new_p[8];
        for(int i = 0; i < 8; i++) {
            int ns0 = next_state[i][0];
            int ns1 = next_state[i][1];
            new_p[i] = p[i] * 100 + p[ns0] * 10 + p[ns1];
        }
        
        // Re-label partitions
        int map[8];
        int count = 0;
        for(int i = 0; i < 8; i++) {
            map[i] = -1;
        }
        
        int p_id[8];
        for(int i = 0; i < 8; i++) {
            int found = -1;
            for(int j = 0; j < i; j++) {
                if(new_p[i] == new_p[j]) {
                    found = p_id[j];
                    break;
                }
            }
            if(found == -1) {
                p_id[i] = count++;
            } else {
                p_id[i] = found;
            }
        }

        for(int i = 0; i < 8; i++) {
            if(p[i] != p_id[i]) {
                changed = 1;
            }
            p[i] = p_id[i];
        }
    }

    // Count unique minimized states
    int unique_states = 0;
    int visited[8] = {0};
    for(int i = 0; i < 8; i++) {
        if(!visited[p[i]]) {
            visited[p[i]] = 1;
            unique_states++;
        }
    }

    printf("Minimum number of states required: %d\n", unique_states);

    return 0;
}

