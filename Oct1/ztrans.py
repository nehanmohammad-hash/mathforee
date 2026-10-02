# By Nehan mohammad
# 01-October-26, Thursday, question no: Q20

import matplotlib.pyplot as plt
import numpy as np
import subprocess

# Load recurrence data from text file
data = np.loadtxt('plotpoint.txt')
n_vals = data[:, 0]
T_vals = data[:, 1]

# Generate smooth points for theoretical curve
n_smooth = np.linspace(n_vals[0], n_vals[-1], 200)
T_theory = (n_smooth * (n_smooth + 1) / 2) * (2 ** n_smooth)

# Plotting the comparison
plt.figure(figsize=(8, 5))
plt.stem(n_vals, T_vals, linefmt='b-', markerfmt='bo', label='Recurrence Data (C)')
plt.plot(n_smooth, T_theory, 'r-', linewidth=0.5, label='Theoretical Equation')

plt.grid(True)
plt.xlabel('n')
plt.ylabel('T(n)')
plt.legend()
plt.savefig('comparison.png', dpi=300, bbox_inches='tight')


