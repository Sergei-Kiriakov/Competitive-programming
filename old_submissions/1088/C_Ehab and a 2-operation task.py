n = int(input())
a = list(map(int, input().split()))
print(n + 1)
print(1, n, 10 ** 6 - a[-1] - 1)
sum = 10 ** 6 - a[-1] - 1
for i in range(1, n):
    print(1, n - i, max(10 ** 6 - (a[n - i - 1] + sum) % (10 ** 6) - i - 1, 0) + min(10 ** 6, 10 ** 6 - (a[n - i - 1] + sum) % (10 ** 6) - i - 1 + 10 ** 6) % (10 ** 6))
    sum += max(10 ** 6 - (a[n - i - 1] + sum) % (10 ** 6) - i - 1, 0) + min(10 ** 6, 10 ** 6 - (a[n - i - 1] + sum) % (10 ** 6) - i - 1 + 10 ** 6) % (10 ** 6)
print(2, n, 10 ** 6)