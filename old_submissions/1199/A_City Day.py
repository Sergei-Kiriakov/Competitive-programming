n, x, y = map(int, input().split())
a = [10 ** 9] * 10 + list(map(int, input().split())) + [10 ** 9] * 10
for i in range(10, len(a)):
    if a[i] == min(a[i - x:i + 1]) == min(a[i:i + y + 1]):
        ans = i
        break
print(ans - 9)