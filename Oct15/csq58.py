# By Nehan mohammad
# 15-October-26, Thursday, question no: probability_stem_plot

import matplotlib.pyplot as plt
import numpy as np
import subprocess

# Load data from the C-generated dat file
data = np.loadtxt('prob_data.dat')
x = data[:, 0]
y = data[:, 1]

# Create high-resolution stem plot
plt.figure(figsize=(8, 5), dpi=300)
markerline, stemlines, baseline = plt.stem(x, y)
plt.setp(stemlines, linewidth=0.5, color='blue')
plt.setp(markerline, markersize=4, color='blue')
plt.setp(baseline, linewidth=0.5, color='red')

plt.title('Probability Density Function Stem Plot')
plt.xlabel('x')
plt.ylabel('P(x)')
plt.grid(True, linestyle='--', alpha=0.6)

# Save and open the plot
filename = 'prob_stem_plot.png'
plt.savefig(filename, dpi=300, bbox_inches='tight')
plt.close()

subprocess.run(['termux-open', filename])

