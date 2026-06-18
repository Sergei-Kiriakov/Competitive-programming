q = int(input())
for i in range(q):
    n = int(input())
    a = list(map(int, list(input())))
    b = list(map(int, list(input())))
    c = [[0 for i in range(n)] for i in range(2)]
    for i in range(n):
        if a[i] < 3:
            c[0][i] = 1
        else:
            c[0][i] = 2
        if b[i] < 3:
            c[1][i] = 1
        else:
            c[1][i] = 2
    last = True
    now = 0
    ind = 0
    last_now = 0
    flag = True
    while ind < n and flag:
        if c[now][ind] == 1:
            if now != last_now:
                flag = False
            else:
                ind += 1
                last_now = now
        else:
            if last_now != now:
                ind += 1
                last_now = now  
            else:
                last_now = now
                now ^= 1
    if now == 1 and ind == n and flag:
        print("YES")
    else:
        print("NO")