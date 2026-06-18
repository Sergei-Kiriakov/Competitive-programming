n = int(input())
a = list(map(int, input().split()))
sum1 = sum(a)
sum2 = 0
i = 0
while sum2 < (sum1 + 1) // 2:
    sum2 += a[i]
    i += 1
print(i)