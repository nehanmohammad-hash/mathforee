# By Nehan mohammad
# 26-October-26, Monday, question no: 58

import matplotlib.pyplot as plt
import numpy as np
import subprocess

# Load u and x values from the C-generated dat file
data = np.loadtxt('random_vars.dat')
u = data[:, 0]
x = data[:, 1]

# Generate smooth x values for the theoretical CDF curve
x_theory = np.linspace(0, 5, 500)
y_theory = np.piecewise(x_theory, 
                        [x_theory < 1, (x_theory >= 1) & (x_theory <= 4), x_theory > 4], 
                        [0.0, lambda t: (t**3 - 1.0) / 63.0, 1.0])

# Create high-resolution plot comparing theoretical CDF and generated stem samples
plt.figure(figsize=(8, 5), dpi=300)
plt.stem(x, u, linefmt='blue', markerfmt='bo', basefmt='r-', label='Generated Samples (u vs x)')
plt.plot(x_theory, y_theory, color='orange', linewidth=0.5, label='Theoretical CDF F(x)')

plt.title('CDF Theoretical Curve vs Generated Samples Stem Plot')
plt.xlabel('x')
plt.ylabel('F(x) / u')
plt.grid(True, linestyle='--', alpha=0.6)
plt.ylim(-0.05, 1.05)
plt.legend()

# Save the figure locally and open it
filename = 'cdf_comparison_plot.png'
plt.savefig(filename, dpi=300, bbox_inches='tight')
plt.close()

subprocess.run(['termux-open', filename])

