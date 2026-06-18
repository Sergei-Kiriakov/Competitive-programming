def main():
    n, k = map(int, input().split())
    k *= 8
    a = sorted(list(map(int, input().split())))
    a1 = [a[0]]
    for i in range(1, n):
        if a[i] != a[i - 1]:
            a1.append(a[i])
    count = k // n
    ans = pow(2, count)
    b = {}
    for i in range(len(a1)):
        b[a1[i]] = i
    c = [0 for i in range(n)]
    for i in range(n):
        c[b[a[i]]] += 1
    pr = [0]
    for i in range(len(a1)):
        pr.append(c[i] + pr[-1])
    min1 = 10 ** 9
    for i in range(len(a1)):
        min1 = min(n - (pr[min(i + ans, len(a1))] - pr[i]), min1)
    print(min1)

main()