def chek(a):
    flag = False
    for i in range(1, len(a)):
        for j in range(1, len(a[i])):
            if a[i][j] <= a[i - 1][j] or a[i][j] <= a[i][j - 1]:
                flag = True
    if flag:
        return False
    return True

n, m = map(int, input().split())
a = [list(map(int, input().split())) for i in range(n)]
b = [list(map(int, input().split())) for i in range(n)]
flag = False
a1 = [[-1 for k in range(m + 1)] for l in range(n + 1)]
for k in range(n):
    for l in range(m):
        a1[k + 1][l + 1] = min(a[k][l], b[k][l])
b1 = [[-1 for k in range(m + 1)] for l in range(n + 1)]
for k in range(n):
    for l in range(m):
        b1[k + 1][l + 1] = max(b[k][l], a[k][l])
if chek(b1) and chek(a1):
    flag = True
if flag:
    print("Possible")
else:
    print("Impossible")