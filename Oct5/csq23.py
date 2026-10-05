# By Nehan mohammad
# 05-October-26, Monday

import numpy as np
import matplotlib.pyplot as plt
import subprocess


print("--- 1. Matrix Rank Analysis for System of Equations ---")
print("Equations:")
print("  x + ky = 1")
print("  kx + y = -1")

print('''k = 1, no solutions
      k = -1, for infinite solution,
      k = any other value for intersection''')
k = float(input("\nEnter value of k: "))
A = np.array([[1, k], [k, 1]])
Aug = np.array([[1, k, 1], [k, 1, -1]])

print(A)
print("Rank of matrix: ", np.linalg.matrix_rank(A))
print(Aug)
print("Rank of matrix: ", np.linalg.matrix_rank(Aug))
rank1 = np.linalg.matrix_rank(A)
rank2 = np.linalg.matrix_rank(Aug)


if rank1 == rank2 and rank1 < 2:
    print("Infinite solutions")
elif rank1 == rank2 and rank1 == 2:
    print("Unique solutions")
elif rank1 != rank2:
    print("No solutions")




x = np.linspace(-5, 5, 400)
plt.figure(figsize=(8, 6))

if k == 0:
    y1 = np.linspace(-10, 10, 1000)
    y2 = -1
    plt.plot(x, y2, linewidth=0.8)
    x =1
    plt.plot(x, y1, linewidth=0.8)
else:
    y1 = (1 - x) / k
    y2 = -1 - k * x
    plt.plot(x, y1, color ='red' )
    plt.plot(x, y2, color='blue')

plt.axhline(0, color='black', linewidth=0.8, linestyle='--')
plt.axvline(0, color='black', linewidth=0.8, linestyle='--')
plt.grid(True, linestyle='--', alpha=0.6)
plt.xlabel('x')
plt.ylabel('y')

filename = 'capelli.png'
plt.savefig(filename, dpi=300, bbox_inches='tight')
plt.close()
print(f"Graph saved as {filename}")

# 3. Open the graph using subprocess
subprocess.run(['termux-open', filename])

