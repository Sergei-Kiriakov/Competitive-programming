n, a, b, c = [int(input()) for i in range(4)]
if a <= (b - c):
    print(n // a + n % a // b)
else:
    g = n // (b - c) - (b - n % (b - c) + b - c - 1) // (b - c)
    g += 1
    g = max(g, 0)
    print((n - g * (b - c)) // a + g)