n, m = map(int, input().split())
c = list(map(int, input().split()))
a = [0 for i in range(n)]
for i in range(m):
    a[c[i] - 1] += 1
print(min(a))