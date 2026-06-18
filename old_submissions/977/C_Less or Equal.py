n, k = map(int, input().split())
a = list(map(int, input().split()))
a = sorted(a)
if k == 0:
    if a[0] == 1:
        print(-1)
    else:
        print(1)
elif k == n:
    print(10 ** 9)
elif a[k - 1] == a[k]:
    print(-1)
else:
    print(a[k - 1])