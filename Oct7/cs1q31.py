# By Nehan mohammad
# 07-October-26, Wednesday, question no: Q.31

import numpy as np
import matplotlib.pyplot as plt
import subprocess

a = 5
b = -2

print(a)
print(b)

x1 = np.linspace(-3, 1, 400)
x2 = np.linspace(1, 3, 400)

y1 = a * x1 + b
y2 = x2**3 + x2**2 + 1

plt.figure(figsize=(8, 5))
plt.plot(x1, y1, color="blue", linewidth=0.5)
plt.plot(x2, y2, color="red", linewidth=0.5)

plt.grid(True)
plt.savefig('q31_plot.png', dpi=300, bbox_inches='tight')

subprocess.run(['termux-open', 'q31_plot.png'])

