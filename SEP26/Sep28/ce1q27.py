import numpy as np

# Define matrix A
A = np.array([[9, 15], [15, 50]], dtype=float)

# Compute Cholesky decomposition (returns lower triangular matrix L in one line)
L = np.linalg.cholesky(A)

print("Lower triangular matrix L:\n", L)
print("l_22 =", L[1, 1])

