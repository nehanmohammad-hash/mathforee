import matplotlib.pyplot as plt
import numpy as np
import sympy as sp
import subprocess


'''
# --- Part 1: Verify and Solve using SymPy ---
x, y = sp.symbols("x y")

# Define the two linear expressions from the square terms
eq1 = x + y - 7
eq2 = 3 * x + y - 13

# Solve the system of equations where both equal 0
solution = sp.solve((eq1, eq2), (x, y))
print(f"Solution for (x, y): {solution}")
'''

import numpy as np

# 1. Define the Coefficient Matrix A and Right-hand side vector B
A = np.array([[1, 1], [3, 1]], dtype=float)

B = np.array([7, 13], dtype=float)

# 2. Construct the Augmented Matrix [A | B]
augmented_matrix = np.column_stack((A, B))
print("--- Augmented Matrix [A | B] ---")
print(augmented_matrix)

# 3. Check Determinant of A to ensure a unique solution exists
det_A = np.linalg.det(A)
print(f"\nDeterminant of A: {det_A:.2f}")

if det_A != 0:
  print("Since det(A) != 0, a unique solution exists.\n")
  solution = np.linalg.solve(A, B)
  print(f"Solution (x, y): {solution}")


# --- Part 2: Plot the Graph using Matplotlib ---
# Generate x values for plotting
x_vals = np.linspace(0, 8, 400)

# Rearrange equations to y = f(x) form
# Line 1: y = 7 - x
# Line 2: y = 13 - 3x
y_line1 = 7 - x_vals
y_line2 = 13 - 3*x_vals

# Set up the plot
plt.figure(figsize=(9, 7))

# Plot Line 1 and Line 2
plt.plot(x_vals, y_line1, label="Line 1: $x + y = 7$", color="royalblue", linewidth=2.5)
plt.plot(
    x_vals, y_line2, label="Line 2: $3x + y = 13$", color="darkorange", linewidth=2.5
)

# Plot the intersection point (3, 4)
plt.scatter([3], [4], color="crimson", s=100, zorder=5, label="Intersection (3, 4)")
plt.annotate(
    "Solution: (3, 4)",
    xy=(3, 4),
    xytext=(3.5, 4.5),
    arrowprops=dict(facecolor="black", shrink=0.05, width=1, headwidth=6),
    fontsize=11,
    fontweight="bold",
)

# Graph styling and limits
plt.xlim(0, 8)
plt.ylim(0, 14)
plt.axhline(0, color="black", linewidth=1)
plt.axvline(0, color="black", linewidth=1)
plt.grid(True, linestyle="--", alpha=0.6)

plt.title(
    "Graphical Verification of System of Linear Equations\n$(x + y - 7)^2 + (y + 3x - 13)^2 = 0$",
    fontsize=12,
    pad=15,
)
plt.xlabel("x-axis", fontsize=11)
plt.ylabel("y-axis", fontsize=11)
plt.legend(fontsize=11)

# Save the figure
plt.savefig("gate_ce_equation_intersection.png", dpi=300, bbox_inches="tight")
print("\nPlot successfully saved as 'gate_ce_equation_intersection.png'.")

subprocess.run(["termux-open", "gate_ce_equation_intersection.png"]);
