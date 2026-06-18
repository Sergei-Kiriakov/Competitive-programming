n = int(input())
m = 2 * (n - 1) - n
ans = 0
for i in range(m + 1):
    if (i == 0 or i == m):
        ans += 4 * 3 * pow(4, (m - 1))
    else:
        ans += 4 * 3 * 3 * pow(4, (m - 2))
print(ans)