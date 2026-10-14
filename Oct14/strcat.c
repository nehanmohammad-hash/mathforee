// By Nehan mohammad
// 14-October-26, Wednesday, question no: pointer_sequence_print_input

#include <stdio.h>

void my_strcat(char *w1, char *w2) {
    char *ptr = w1;
    
    // Point to the first word and print it
    printf("%s", ptr);
    
    // Point to the next word and print it
    ptr = w2;
    printf("%s\n", ptr);
}

int main() {
    char word1[100];
    char word2[100];

    // Read the first word/sentence up to 99 characters
    printf("Enter first word: ");
    scanf("%99[^\n]", word1);
    getchar(); // Consume the leftover newline character from the input buffer

    // Read the second word/sentence up to 99 characters
    printf("Enter second word: ");
    scanf("%99[^\n]", word2);

    // Pass them to the function that uses pointers to print them sequentially
    my_strcat(word1, word2);

    return 0;
}
