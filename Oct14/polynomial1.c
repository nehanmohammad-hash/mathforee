// By Nehan mohammad
// 14-October-26, Wednesday, polynomial_dynamic_input

#include <stdio.h>

typedef struct {
    int degree;
    double coeffs[21]; // n <= 20, accommodating a0 through a20
} Poly;

int main() {
    Poly p;

    // Initialize all coefficients to 0.0
    for (int i = 0; i <= 20; i++) {
        p.coeffs[i] = 0.0;
    }

    char buffer[1024];
    printf("Enter the coefficients (from a0 onwards, separated by spaces): ");
    
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        char *ptr = buffer;
        int count = 0;
        double val;
        int chars_read;

        // Read up to 21 coefficients; extra inputs beyond 21 are automatically ignored
        while (count < 21 && sscanf(ptr, "%lf%n", &val, &chars_read) == 1) {
            p.coeffs[count] = val;
            count++;
            ptr += chars_read;
        }

        if (count == 0) {
            p.degree = 0;
            p.coeffs[0] = 0.0;
        } else {
            p.degree = count - 1; // Degree is determined by the number of coefficients entered
        }
    }

    // Accept floating-point number a
    double a;
    printf("Enter the floating-point number a: ");
    scanf("%lf", &a);

    // (i) Compute and print the value of P(a)
    double p_val = 0.0;
    double x_power = 1.0;
    for (int i = 0; i <= p.degree; i++) {
        p_val += p.coeffs[i] * x_power;
        x_power *= a;
    }
    printf("\n(i) Value of P(%.2f) = %.4f\n", a, p_val);

    // (ii) Compute the derivative and store it in another Poly variable
    Poly deriv;
    if (p.degree == 0) {
        deriv.degree = 0;
        deriv.coeffs[0] = 0.0;
    } else {
        deriv.degree = p.degree - 1;
        for (int i = 0; i <= deriv.degree; i++) {
            deriv.coeffs[i] = (i + 1) * p.coeffs[i + 1];
        }
    }

    // Print derivative details
    printf("(ii) Derivative Polynomial P'(x) stored in Poly type:\n");
    printf("     Degree: %d\n", deriv.degree);
    printf("     Coefficients: ");
    for (int i = 0; i <= deriv.degree; i++) {
        printf("%.2f ", deriv.coeffs[i]);
    }
    printf("\n");

    return 0;
}
