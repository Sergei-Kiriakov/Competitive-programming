a = list(map(int, input().split()))
count = 0
max_count = 0
for i in range(14):
    b = []
    for l in range(14):
        b.append(a[l])
    n = b[i]
    b[i] = 0
    if n > 0:
        for j in range(i + 1, i + 1 + n % 14):
            b[j % 14] += n // 14 + 1
        for h in range(i + 1 + n % 14, 14 + i + 1):
            b[h % 14] += n // 14
        for k in range(14):
            if b[k] % 2 == 0:
                count += b[k]
        max_count = max(count, max_count)
        count = 0
print(max_count)