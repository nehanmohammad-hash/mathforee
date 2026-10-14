// By Nehan mohammad
// 14-October-26, Wednesday, question no: polynomial_operations

#include <stdio.h>

typedef struct {
    int degree;
    double coeffs[21]; // n <= 20, accommodating a0 through a20[cite: 3]
} Poly;

int main() {
    Poly p;

    // Accept degree of the polynomial
    printf("Enter the degree of the polynomial (n <= 20): ");
    scanf("%d", &p.degree);

    if (p.degree < 0 || p.degree > 20) {
        printf("Error: Degree must be between 0 and 20.\n");
        return 1;
    }

    // Accept coefficients from a0 to an
    printf("Enter %d coefficients (from a0 to a%d):\n", p.degree + 1, p.degree);
    for (int i = 0; i <= p.degree; i++) {
        scanf("%lf", &p.coeffs[i]);
    }

    // Accept floating-point number
    double a;
    printf("Enter the floating-point number a: ");
    scanf("%lf", &a);

    // (i) Compute and print the value of P(a)[cite: 3]
    double p_val = 0.0;
    double x_power = 1.0;
    for (int i = 0; i <= p.degree; i++) {
        p_val += p.coeffs[i] * x_power;
        x_power *= a;
    }
    printf("\n(i) Value of P(%.2f) = %.4f\n", a, p_val);

    // (ii) Compute the derivative and store it in another Poly variable[cite: 3]
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
