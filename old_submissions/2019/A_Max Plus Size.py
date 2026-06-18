t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    max_a = max(a)
    dp0 = [-1] * 1001  # dp[i][0][maxval]
    dp1 = [-1] * 1001  # dp[i][1][maxval]
    dp0[0] = 0  # At position 0, no elements selected, maxval = 0
    for i in range(n):
        new_dp0 = [-1] * 1001
        new_dp1 = [-1] * 1001
        for maxval in range(1001):
            if dp0[maxval] >= 0 or dp1[maxval] >= 0:
                # Not selecting current element
                val0 = max(dp0[maxval], dp1[maxval])
                if new_dp0[maxval] < val0:
                    new_dp0[maxval] = val0
            if dp0[maxval] >= 0:
                # Selecting current element
                new_maxval = max(maxval, a[i])
                new_count = dp0[maxval] + 1
                if new_dp1[new_maxval] < new_count:
                    new_dp1[new_maxval] = new_count
        dp0 = new_dp0
        dp1 = new_dp1
    ans = 0
    for maxval in range(1001):
        if dp0[maxval] >= 0:
            total_score = maxval + dp0[maxval]
            if total_score > ans:
                ans = total_score
        if dp1[maxval] >= 0:
            total_score = maxval + dp1[maxval]
            if total_score > ans:
                ans = total_score
    print(ans)