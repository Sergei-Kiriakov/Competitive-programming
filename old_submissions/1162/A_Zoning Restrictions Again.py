n, h, m = map(int, input().split())
a = [list(map(int, input().split())) for i in range(m)]
a.sort(key=lambda x: x[2])
count = 0
mest = 0
b = [0 for i in range(n)]
for i in range(len(a)):
    for j in range(a[i][0] - 1, a[i][1]):
        if b[j] == 0:
            b[j] = 1
            count += (min(h, a[i][2]) ** 2)
            mest += 1
print(count + (n - mest) * (h ** 2))