n = int(input())
a = list(map(int, input().split()))
a1 = sorted(a)
flag = False
for i in range(n- 1):
    if a[i] == a[i + 1]:
        flag = True
if flag:
    print("NO")
else:
    j = 0 
    g = 0
    while a[g] != a1[-j - 1]:
        g += 1
    r = g + 1
    l = g - 1
    j = 1
    flag = False
    while j < n:
        if r < n and a[r] == a1[-j - 1]:
            r += 1
            j += 1
        elif l > -1 and a[l] == a1[-j - 1]:
            l -= 1
            j += 1
        else:
            flag = True
            break
    if flag:
        print("NO")
    else:
        print("YES")