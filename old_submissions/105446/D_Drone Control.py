def solve():
    p, r, y = map(float, input().split())
    e = abs(p)/2
    w = -abs(p)/2
    n = abs(r)/2
    s = -abs(r)/2
    mx = max(e, n)

    curr_sum = sum([e, w, n, s])
    dist = abs(y - curr_sum)
    if y < curr_sum:
        offset = min(dist/2, abs(w+mx))
        e -= offset
        w -= offset

    curr_sum = sum([e, w, n, s])
    dist = abs(y - curr_sum)
    if y < curr_sum:
        offset = min(dist/2, abs(s+mx))
        n -= offset
        s -= offset

    curr_sum = sum([e, w, n, s])
    dist = abs(y - curr_sum)
    if y < curr_sum:
        offset = dist/4
        e -= offset
        w -= offset
        n -= offset
        s -= offset

    curr_sum = sum([e, w, n, s])
    dist = abs(y - curr_sum)
    if y > curr_sum:
        offset = min(dist/2, abs(mx-e))
        e += offset
        w += offset

    curr_sum = sum([e, w, n, s])
    dist = abs(y - curr_sum)
    if y > curr_sum:
        offset = min(dist/2, abs(mx-n))
        n += offset
        s += offset

    curr_sum = sum([e, w, n, s])
    dist = abs(y - curr_sum)
    if y > curr_sum:
        offset = dist/4
        e += offset
        w += offset
        n += offset
        s += offset

    if p<0:
        e, w = w, e
    if r<0:
        n, s = s, n
    print(n, e, s, w)

n = int(input())
for i in range(n):
    solve()
