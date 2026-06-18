n, m, k = map(int, input().split())
a = list(map(int, input().split()))
c = max(a)
j = a.index(c)
max1 = -1
for i in range(n):
    if i != j:
        max1 = max(max1, a[i])
print((c * k + max1) * (m // (k + 1)) + c * (m % (k + 1)))