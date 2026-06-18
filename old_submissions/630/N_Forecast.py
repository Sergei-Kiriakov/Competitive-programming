a, b, c = map(int, input().split())
f = lambda x : a * x ** 2 + b * x + c
xv = -b / (2 * a)
l1 = -1e12
r1 = xv
while (r1 - l1 > 1e-6):
    mid1 = (r1 + l1) / 2
    if (f(mid1) * f(r1) <= 0):
        l1 = mid1
    else:
        r1 = mid1
r2 = 1e12
l2 = xv
while (r2 - l2 > 1e-6):
    mid2 = (r2 + l2) / 2
    if (f(mid2) * f(r2) <= 0):
        l2 = mid2
    else:
        r2 = mid2
print(l2, l1)