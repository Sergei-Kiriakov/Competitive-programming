mod = 10 ** 9 + 7
s = input()
n = len(s)
ans = 1
flag = False
for i in range(n):
    if s[i] == "w" or s[i] == "m":
        flag = True
if flag:
    print(0)
else:
    count = 0
    if s[0] == "u" or s[0] == "n":
        count += 1
    for i in range(1, n):
        if s[i] == s[i - 1] and (s[i] == "u" or s[i] == "n"):
            count += 1        
        else:
            ans1 = 1
            ans2 = 1
            for j in range(count - 1):
                ans1, ans2 = (ans1 + ans2) % mod, ans1
            count = 0
            ans = (ans1 * ans) % mod
            if s[i] == "u" or s[i] == "n":
                count += 1
    if count != 0:
        ans1 = 1
        ans2 = 1
        for j in range(count - 1):
            ans1, ans2 = (ans1 + ans2) % mod, ans1
        count = 0
        ans = (ans1 * ans) % mod  
    print(ans % mod)