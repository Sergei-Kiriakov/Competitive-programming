q = int(input())
for i in range(q):
    a = sorted(list(map(int, input().split())))
    print(a[0] + (a[1] - a[0]) + (a[2] - (a[1] - a[0])) // 2)