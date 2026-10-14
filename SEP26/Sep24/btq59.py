# Code by Nehan Mohammad
# Gate 2025, Biotechnology, question 59.

# Given Parameters
power_limit = 10

# Calculate sequence iteratively
a = 0
n = 0
threshold = 1 / (2 ** power_limit)

while abs(1 - a) >= threshold:
    a = 0.5 * (1 + a)
    n += 1

print(f" Power limit exponent: {power_limit},\n Required value <= 1/2^10")
print(f"Least value of n: {n}")

# print(f"Absolute difference |1 - a_n|: {abs(1 - a):.8f}")
