def f(n):
    d = 2
    count = 0
    while d * d < n:
        if n % d == 0:
            count += 2
        d += 1
    if d * d == n:
        count += 1
    return count

t = int(input())
for i in range(t):
    n = int(input())
    a = sorted(list(map(int, input().split())))
    if n % 2 == 1:
        h = a[n // 2] ** 2
        l = f(h)
        flag = True
        for i in range(n // 2):
            if a[i] * a[-i - 1] != h:
                flag = False
        if flag and l == n:
            print(h)
        else:
            print(-1)
    else:
        h = a[0] * a[-1]
        l = f(h)
        flag = True
        for i in range(n // 2):
            if a[i] * a[-i - 1] != h:
                flag = False
        if flag and l == n:
            print(h)
        else:
            print(-1)        