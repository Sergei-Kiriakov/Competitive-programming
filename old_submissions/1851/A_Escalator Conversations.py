def solve():
    n, m, k, h = map(int, input().split())
    a = list(map(int, input().split()))
    ans = 0
    for i in range(n):
        d = abs(h - a[i])
        if d != 0 and d % k == 0 and d // k < m:
            ans += 1
    print(ans)

def main():
    t = int(input())
    for i in range(t):
        solve()

main()

