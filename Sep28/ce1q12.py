import matplotlib.pyplot as plt
import numpy as np

# Define the coefficient matrix A for the system:
# x1 + x2 + x3 = 0
# x1 + 2x3 = 0
A = np.array([[1, 1, 1], [1, 0, 2]], dtype=float)

# Print system matrix
print("Coefficient Matrix A:")
print(A)

# Direction vector m (Null space basis vector: [-2, 1, 1])
# Derived from row reduction: x1 = -2t, x2 = t, x3 = t
m = np.array([-2, 1, 1], dtype=float)
print(f"\nDirection Vector (m): {m}")

# Generate points along the line: x = t * m for t in range [-5, 5]
t = np.linspace(-5, 5, 100)
line_x1 = m[0] * t
line_x2 = m[1] * t
line_x3 = m[2] * t

# Set up the 3D plot
fig = plt.figure(figsize=(10, 8))
ax = fig.add_subplot(projection="3d")

# Plot the intersection line
ax.plot(
    line_x1,
    line_x2,
    line_x3,
    label="Line: $\\mathbf{x} = t[-2, 1, 1]^T$",
    color="crimson",
    linewidth=3,
)

# Plot the origin point
ax.scatter([0], [0], [0], color="black", s=50, label="Origin (0,0,0)")

# Labels and formatting
ax.set_title(
    "Geometric Solution of Homogeneous System\nIntersection of Two Planes in 3D Space",
    fontsize=12,
    pad=15,
)
ax.set_xlabel("$x_1$ Axis")
ax.set_ylabel("$x_2$ Axis")
ax.set_zlabel("$x_3$ Axis")
ax.legend()

# Set equal aspect ratio for accurate 3D geometry representation
ax.set_box_aspect([1, 1, 1])

# Save the figure to file
plt.savefig(
    "gate_ce_line_intersection.png", dpi=300, bbox_inches="tight"
)
print("\nPlot successfully saved as 'gate_ce_line_intersection.png'.")

# Show the plot window
plt.show()

