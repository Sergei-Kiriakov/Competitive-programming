n = int(input())
s = input()
ans = ""
for i in range(len(s) // 2):
    if s[:i + 1] == s[i + 1: 2 * (i + 1)]:
        ans = s[:i + 1]
if len(ans) > 1:
    print(len(s) - len(ans) + 1)
else:
    print(len(s))