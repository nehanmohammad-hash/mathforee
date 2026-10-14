// By Nehan mohammad
// 14-October-26, Wednesday, question no: complex_struct_arithmetic

#include <stdio.h>

struct complex {
    double real;
    double imag;
};

// Function to compute the sum of two complex numbers
struct complex add_complex(struct complex c1, struct complex c2) {
    struct complex result;
    result.real = c1.real + c2.real;
    result.imag = c1.imag + c2.imag;
    return result;
}

// Function to compute the product of two complex numbers
struct complex multiply_complex(struct complex c1, struct complex c2) {
    struct complex result;
    // (a + bi) * (c + di) = (ac - bd) + (ad + bc)i
    result.real = (c1.real * c2.real) - (c1.imag * c2.imag);
    result.imag = (c1.real * c2.imag) + (c1.imag * c2.real);
    return result;
}

int main() {
    struct complex c1, c2, sum, product;

    // Accept first complex number
    printf("Enter real and imaginary parts of the first complex number:\n");
    scanf("%lf %lf", &c1.real, &c1.imag);

    // Accept second complex number
    printf("Enter real and imaginary parts of the second complex number:\n");
    scanf("%lf %lf", &c2.real, &c2.imag);

    // Compute sum and product
    sum = add_complex(c1, c2);
    product = multiply_complex(c1, c2);

    // Print results
    printf("\n--- Results ---\n");
    printf("First Complex Number:  %.2f + %.2fi\n", c1.real, c1.imag);
    printf("Second Complex Number: %.2f + %.2fi\n", c2.real, c2.imag);
    printf("Sum:                   %.2f + %.2fi\n", sum.real, sum.imag);
    printf("Product:               %.2f + %.2fi\n", product.real, product.imag);

    return 0;
}
