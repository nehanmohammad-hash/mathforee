import numpy as np
import matplotlib.pyplot as plt
import subprocess

# 1. Enter value of k
k = 4
# k = 5

# 2. Define x range
x = np.linspace(-6, 6, 400)

# 3. Calculate y values for both equations
# Equation 1: 2x + 3y = 6  =>  y = (6 - 2x) / 3
y1 = (6.0 - 2.0 * x) / 3.0

# Equation 2: 4x + 6y = 3k  =>  y = (3k - 4x) / 6
y2 = (3.0 * k - 4.0 * x) / 6.0

# 4. Set up the plot
plt.figure(figsize=(8, 6))
plt.plot(x, y1, label='$2x + 3y = 6$', color='blue', linewidth=1.4)
plt.plot(x, y2, label=f'$4x + 6y = 3({k})$', color='red', linewidth=1.2)

# Reference axes lines
plt.axhline(0, color='black', linewidth=0.8, linestyle='-')
plt.axvline(0, color='black', linewidth=0.8, linestyle='-')

plt.title(f"Linear System Graph for k = {k}", fontsize=14)
plt.xlabel("$x$", fontsize=12)
plt.ylabel("$y$", fontsize=12)
#plt.grid(True, linestyle='--', alpha=0.6)
plt.legend()

# 5. Save the plot dynamically with the k value in the filename
filename = f'system_k_{k}.pdf'
plt.savefig(filename, dpi=300)
plt.close()

print(f"Plot successfully saved as {filename}.")

# 6. Automatically open the image using termux-open
subprocess.run(['termux-open', filename])

