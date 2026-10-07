#include <stdio.h>

int main() {
    int valid_count = 0;
    int total_strings = 243; // 3^5 possible ternary strings of length 5

    for (int i = 0; i < total_strings; i++) {
        int temp = i;
        int s[5];
        
        // Convert number to base-3 digits representing the string
        for (int j = 4; j >= 0; j--) {
            s[j] = temp % 3;
            temp /= 3;
        }

        // Check for at least one pair of consecutive identical symbols
        int has_consecutive = 0;
        for (int j = 0; j < 4; j++) {
            if (s[j] == s[j+1]) {
                has_consecutive = 1;
                break;
            }
        }

        if (has_consecutive) {
            valid_count++;
        }
    }

    printf("Result: %d\n", valid_count);
    return 0;
}

