def main():
    n = int(input())
    a = [list(map(int, input().split())) for i in range(n)]
    m = int(input())
    for i in range(m):
        a.append(list(map(int, input().split())))
    a = sorted(a)
    count = 0
    i = 0
    while i < n + m:
        if i + 1 < n + m and a[i][0] == a[i + 1][0]:
            count += max(a[i][1], a[i + 1][1])
            i += 1
        else:
            count += a[i][1]
        i += 1
    print(count)
main()