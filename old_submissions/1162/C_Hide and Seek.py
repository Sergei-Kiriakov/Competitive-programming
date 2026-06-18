n, k = map(int, input().split())
a = list(map(int, input().split()))
count = (n - 1) * 2 + n
b = [[0, -1] for i in range(n + 2)]
c = set()
for i in range(len(a)):
    if b[a[i] - 1][0] != 0 and b[a[i]][0] == 0:
        count -= 1
    if b[a[i] + 1][0] != 0 and b[a[i]][0] == 0:
        count -= 1
    if b[a[i]][0] == 0:
        count -= 1
    l1 = (a[i] + 1, a[i])
    l2 = (a[i], a[i] + 1)
    if b[a[i] + 1][1] > b[a[i]][1] and b[a[i] + 1][0] != 0 and b[a[i]][0] != 0 and l1 not in c and l2 not in c:
        count -= 1
        c.add(l1)
        c.add(l2)
    l3 = (a[i], a[i] - 1)
    l4 = (a[i] - 1, a[i])
    if b[a[i] - 1][1] > b[a[i]][1] and b[a[i] - 1][0] != 0 and b[a[i]][0] != 0 and l3 not in c and l4 not in c:
        count -= 1
        c.add(l3)
        c.add(l4)        
    b[a[i]][0] = 1
    b[a[i]][1] = i
print(count)