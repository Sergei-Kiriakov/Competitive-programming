n, k = map(int, input().split())
a = list(map(int, input().split()))
c = set()
ans = []
last = 0
for i in range(n):
    if a[i] not in c:
        if len(ans) < k:
            ans.append(a[i])
        else:
            c.remove(ans[last])
            ans.append(a[i])
            last += 1
        c.add(a[i])
print(min(len(ans), k))
for i in range(min(len(ans), k)):
    print(ans[-i - 1], end=" ")