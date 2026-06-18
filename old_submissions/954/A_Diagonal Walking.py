n = int(input())
s = input()
count = len(s)
i = 1
while i < len(s):
    if (s[i] == "U" and s[i - 1] == "R") or (s[i] == "R" and s[i - 1] == "U"):
        count -= 1
        i += 1
    i += 1
print(count)