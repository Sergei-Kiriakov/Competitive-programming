def solve():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    if a[0] == a[n - 1]:
        cnt = 0
        for el in a:
            if el == a[n - 1]:
                cnt += 1
        if cnt >= k:
            print("YES")
        else:
            print("NO")
        return
    cnt_start = 0
    cnt_finish = 0
    i = 0
    while i < n and cnt_start < k:
        if a[0] == a[i]:
            cnt_start += 1
        i += 1
    while i < n:
        if a[i] == a[n - 1]:
            cnt_finish += 1
        i += 1
    if cnt_start >= k and cnt_finish >= k:
        print("YES")
    else:
        print("NO")

def main():
    t = int(input())
    for i in range(t):
        solve()

main()
