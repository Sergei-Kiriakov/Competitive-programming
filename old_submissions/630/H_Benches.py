from math import comb, factorial
n = int(input())
d = n * n
ans = 1
for i in range(5):
    ans *= d
    d -= 2 * n - 1
    n -= 1
print(ans // factorial(5))