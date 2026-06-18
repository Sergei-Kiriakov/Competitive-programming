q = int(input())
ans = []
for i in range(q):
    n, m, k = map(int, input().split())
    if n > m:
        n, m = m, n
    min1 = m
    if min1 > k:
        ans.append(-1)
    else:
        if (n + m) % 2 == 0:
            if (k - min1) % 2 == 1:
                ans.append(k - 2)
            else:
                ans.append(k)
        else:
            ans.append(k - 1)
for i in range(q):
    print(ans[i])