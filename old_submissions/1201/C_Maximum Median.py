def main():
    n, k = map(int, input().split())
    a = sorted(list(map(int, input().split())))
    i = n // 2
    count = k
    ans = a[n // 2]
    while i < n - 1 and count - (a[i + 1] - a[i]) * (i - n // 2 + 1) >= 0:
        count -= (a[i + 1] - a[i]) * (i - n // 2 + 1)
        ans = a[i + 1]
        i += 1
    print(ans + count // (i - n // 2 + 1))

main()