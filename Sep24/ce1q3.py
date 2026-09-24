# Code by Nehan Mohammad
# Visualizing curves from GATE Civil Engineering Question 3

import numpy as np
import matplotlib.pyplot as plt

# Generate x values across a broad range to cover vertex and behavior
x = np.linspace(-4, 2, 500)

# Define the two parabolas
y1 = x**2
y2 = -x**2 - 2*x - 1

# Create the plot
plt.figure(figsize=(8, 6))
plt.plot(x, y1, label='y = x^2', color='blue', linewidth=1)
plt.plot(x, y2, label='y = -x^2 - 2x - 1', color='red', linewidth=1)

# Customize plot layout
plt.title('Graphical Check: Intersection of Curves')
plt.xlabel('x')
plt.ylabel('y')
plt.axhline(0, color='black', linewidth=0.8, linestyle='--')
plt.axvline(0, color='black', linewidth=0.8, linestyle='--')
plt.grid(True, linestyle=':', alpha=0.6)
plt.legend()

# Display the visualization
#plt.show()
plt.savefig('ce2q3graph.png', dpi=300, bbox_inches='tight')

