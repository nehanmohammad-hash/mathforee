# Code by Nehan Mohammad
# Verification of properties for Matrix P (GATE 2026 CE Q11)

import numpy as np

# Define Matrix P
P = np.array([
    [1, 0, 1],
    [0, 1, 0],
    [1, 0, 1]
])

print("--- 1. RANK, SINGULARITY & INVERTIBILITY ---")
rank = np.linalg.matrix_rank(P)
det = np.linalg.det(P)
print(f"Matrix P:\n{P}")
print(f"Rank of P: {rank}")
print(f"Determinant of P: {det:.4f}")

# Check P @ P.T vs Identity
PT_P = P @ P.T
identity_check = np.allclose(PT_P, np.eye(3))
print(f"P * P^T:\n{PT_P}")
print("P is a singular matrice and is therefore non invertible. P @ PT != 0")


print("--- 2. SKEW-SYMMETRY CHECK ---")
PT = P.T
is_skew_symmetric = np.allclose(P, -PT)
print(f"Is P skew-symmetric (P == -P^T)? {is_skew_symmetric}\n")
print(f" -P^T =\n {P.T}")

print("--- 3. EIGENVALUES & TRACE CHECK ---")
eigenvalues = np.linalg.eigvalsh(P) # Using eigvalsh since P is symmetric
trace_P = np.trace(P)
sum_eigenvalues = np.sum(eigenvalues)

print(f"Eigenvalues: {eigenvalues}")
print(f"Trace of P: {trace_P}")
print(f"Sum of Eigenvalues: {sum_eigenvalues}")
print("Traceof P == Sum of Eigenvalues")
