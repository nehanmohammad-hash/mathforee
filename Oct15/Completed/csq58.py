# By Nehan mohammad
# 15-October-26, Thursday, question no: probability_curve_plot

import matplotlib.pyplot as plt
import numpy as np
import subprocess

# Define the probability density function P(x)
def pdf(x):
    C = 1 / 21
    return np.where((x >= 1) & (x <= 4), C * (x ** 2), 0.0)

# Generate x values across and beyond the domain
x = np.linspace(0, 5, 500)
y = pdf(x)

# Create high-resolution plot with thin lines and grid
plt.figure(figsize=(8, 5), dpi=300)
plt.plot(x, y, color='blue', linewidth=0.5, label='P(x) = C x^2')

# Highlight the region between 2 and 3
x_shaded = np.linspace(2, 3, 100)
plt.fill_between(x_shaded, pdf(x_shaded), color='orange', alpha=0.4, label='P(2 <= x <= 3)')

plt.title('Probability Density Function')
plt.xlabel('x')
plt.ylabel('P(x)')
plt.grid(True, linestyle='--', alpha=0.6)
plt.legend()

# Save the figure locally
filename = 'probability_curve.png'
plt.savefig(filename, dpi=300, bbox_inches='tight')
plt.close()

# Automatically open the image via termux-open
subprocess.run(['termux-open', filename])

