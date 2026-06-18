t = int(input())
for i in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    max1 = 0
    max2 = 0
    for i in range(n):
        if a[i] > max1:
            max2 = max1
            max1 = a[i]
        else:
            max2 = max(max2, a[i])
    print(max(min(max2 - 1, n - 2), 0))