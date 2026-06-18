from math import comb, factorial
n = int(input())
if (n == 1):
    print(1)
else:
    print(comb(n + 4, 5) * comb(n + 2, 3))