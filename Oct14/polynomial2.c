// By Nehan mohammad
// 14-October-26, Wednesday, question no: polynomial_pointer_list

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int degree;
    double *coeffs; // Pointer acting as a dynamic list for coefficients
} Poly;

int main() {
    Poly p;
    p.degree = 0;
    p.coeffs = NULL;

    char buffer[1024];
    printf("Enter the coefficients (from a0 onwards, separated by spaces): ");
    
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        char *ptr = buffer;
        int count = 0;
        double val;
        int chars_read;
        double *temp_coeffs = NULL;

        // Dynamically read coefficients using pointers and realloc
        while (sscanf(ptr, "%lf%n", &val, &chars_read) == 1) {
            double *new_coeffs = realloc(temp_coeffs, (count + 1) * sizeof(double));
            if (new_coeffs == NULL) {
                printf("Memory allocation failed!\n");
                free(temp_coeffs);
                return 1;
            }
            temp_coeffs = new_coeffs;
            temp_coeffs[count] = val;
            count++;
            ptr += chars_read;
        }

        if (count == 0) {
            p.degree = 0;
            p.coeffs = malloc(sizeof(double));
            p.coeffs[0] = 0.0;
        } else {
            p.degree = count - 1;
            p.coeffs = temp_coeffs;
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

    // (ii) Compute the derivative and store it in another Poly variable using pointers
    Poly deriv;
    if (p.degree == 0) {
        deriv.degree = 0;
        deriv.coeffs = malloc(sizeof(double));
        deriv.coeffs[0] = 0.0;
    } else {
        deriv.degree = p.degree - 1;
        deriv.coeffs = malloc((deriv.degree + 1) * sizeof(double));
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

    // Free dynamically allocated memory
    free(p.coeffs);
    free(deriv.coeffs);

    return 0;
}
