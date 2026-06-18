t = int(input())
for i in range(t):
    a, b, c = map(int, input().split())
    l = 0
    r = c + 1
    while l < r:
        m = (r + l) // 2
        if a + m > b + c - m:
            r = m
        else:
            l = m + 1
    if (l > c):
        print(0)
    else:
        print(c - l + 1)
    