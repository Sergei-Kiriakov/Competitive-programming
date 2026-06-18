n, k = map(int, input().split())
a = [[0 for i in range(n)] for i in range(n)]
count = 1
for i in range(n):
    for j in range(k - 1):
        a[i][j] = count
        count += 1
for i in range(n):
    for j in range(k - 1, n):
        a[i][j] = count
        count += 1
sum1 = 0
for i in range(n):
    sum1 += a[i][k - 1]
print(sum1)
for i in range(n):
    for j in range(n):
        print(a[i][j], end=" ")
    print()