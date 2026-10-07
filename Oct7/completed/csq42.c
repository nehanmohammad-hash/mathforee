// By Nehan mohammad
// 07-October-26, Wednesday, question no: Q42
#include <stdio.h>
// Function that takes a number, an array, and size, then fills the array with its bits
void int_to_binary_array(int num, int bits[], int size)
{
	for (int i = 0; i < size; i++)
	{
	// Extracts bits from right to left and places them into the array
	bits[size - 1 - i] = (num >> i) & 1;
	}
}
int main()
	{
	printf("b3 b2 b1 b0 | F\n");
	printf("-------------\n");
	// Loop through 0 to 15 for 4 variables
	for (int i = 0; i < 16; i++)
	{
		int bit[4]; // Array to hold 4 bits
		// Automatically convert the integer into a binary array
		int_to_binary_array(i, bit, 4);
		int b3 = bit[0], b2 = bit[1], b1 = bit[2], b0 = bit[3];
		// Boolean logic provided by you: (b1 & !b2 & !b0) | (!b1 & !b0) | (b3 & !b2 & b1)
		int output = (b1 && !b2 && !b0) || (!b1 && !b0) || (b3 && !b2 && b1);
		printf(" %d  %d  %d  %d  | %d\n", b3, b2, b1, b0, output);
	}
	return 0;
}

