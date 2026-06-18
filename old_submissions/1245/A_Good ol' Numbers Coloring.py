def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a

t = int(input())
for i in range(t):
    a, b = map(int, input().split())
    if gcd(a, b) == 1:
        print("Finite")
    else:
        print("Infinite")
    