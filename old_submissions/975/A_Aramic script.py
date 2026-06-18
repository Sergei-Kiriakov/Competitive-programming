n = int(input())
a = input().split()
s1 = []
s2 = []
count = 0
for i in range(n):
    for j in range(len(a[i])):
        if a[i][j] not in s1:
            s1.append(a[i][j])
    k = sorted(s1)
    if k not in s2:
        count += 1
    s2.append(k)
    s1 = []
    k = []
print(count)