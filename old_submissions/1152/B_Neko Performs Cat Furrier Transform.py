def rec(s):
    ans.append(len(s))
    for i in range(len(s)):
        if s[i] == "1":
            s[i] = "0"
        else:
            s[i] = "1"
    count[0] += 1
    i = 0
    while s != [] and s[0] == "0":
        s.pop(0)    
    if s == ["1"] * len(s):
        return 0    
    while i < len(s) and s[- i - 1] == "1":
        s[-i - 1] = "0"
        i += 1
    if i == len(s):
        s = ["1"] + s
    else:
        s[-i - 1] = "1"
    count[0] += 1
    if s == ["1"] * len(s):
        return 0
    if s != []:
        return rec(s)
    else:
        return 0

t = int(input())
s = list(bin(t)[2:])
ans = []
count = [0]
c = rec(s)
print(count[0])
for i in range(len(ans)):
    print(ans[i], end=" ")