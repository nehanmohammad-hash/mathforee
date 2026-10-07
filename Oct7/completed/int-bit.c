#include <stdio.h>

// Generalized function: checks if an array has at least 'k' bits set to 1
int has_at_least_k_ones(int arr[], int size, int k) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == 1) {
            count++;
        }
    }
    return (count >= k);
}

// Function to convert any number into a binary array of arbitrary size
void int_to_binary_array(int num, int bits[], int size) {
    for (int i = 0; i < size; i++) {
        bits[size - 1 - i] = (num >> i) & 1;
    }
}

int main() {
    int num_bits = 4; // You can change this to 3, 4, 8, etc. easily!
    int threshold = 2; // We want to check if at least 2 bits are 1
    int total_combinations = 1 << num_bits; // 2^num_bits combinations

    printf("Checking for at least %d ones across %d-bit numbers:\n", threshold, num_bits);
    printf("----------------------------------------\n");

    // Loop through all possible combinations for the given number of bits
    for (int i = 0; i < total_combinations; i++) {
        int bits[num_bits];
        int_to_binary_array(i, bits, num_bits);

        // Iteratively check the array using our generalized function
        int output = has_at_least_k_ones(bits, num_bits, threshold);

        // Print the binary array representation
        for (int j = 0; j < num_bits; j++) {
            printf("%d ", bits[j]);
        }
        printf("|   Output: %d\n", output);
    }

    return 0;
}

