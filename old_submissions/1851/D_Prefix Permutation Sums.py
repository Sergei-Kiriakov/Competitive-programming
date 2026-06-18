def check(a):
    ans = True
    for i in range(1, len(a) - 1):
        if a[i] != 1:
            ans = False
    return ans

def solve():
    n = int(input())
    a = list(map(int, input().split()))
    cnt = [0 for i in range(n + 2)]
    if a[0] > n:
        cnt[n + 1] = a[0]
    else:
        cnt[a[0]] += 1
    for i in range(n - 2):
        d = a[i + 1] - a[i]
        if d > n:
            cnt[n + 1] = d
        else:
            cnt[d] += 1
    f1, f2 = -1, -1
    for i in range(1, n + 1):
        if cnt[i] == 0:
            if f1 == -1:
                f1 = i
            else:
                f2 = i
    ind = -1
    cnt2 = 0
    for i in range(1, n + 1):
        if cnt[i] == 2:
            cnt2 += 1
            ind = i
    if cnt[n + 1] != 0:
        cnt[f1] += 1
        cnt[f2] += 1
        if f1 + f2 == cnt[n + 1] and check(cnt):
            print("YES")
        else:
            print("NO")
        return
    if cnt2 == 1:
        cnt[f1] += 1
        cnt[f2] += 1
        cnt[ind] -= 1
        if f1 + f2 == ind and check(cnt):
            print("YES")
        else:
            print("NO")
        return
    if f1 != -1:
        cnt[f1] += 1
        if check(cnt):
            print("YES")
        else:
            print("NO")
        return
    print("NO")
def main():
    t = int(input())
    for i in range(t):
        solve()

main()
