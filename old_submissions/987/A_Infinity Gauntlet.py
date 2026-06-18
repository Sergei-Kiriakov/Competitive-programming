n = int(input())
a = ["purple", "green", "blue", "orange", "red", "yellow"]
ans = [0 for i in range(6)]
b = ["Power", "Time", "Space", "Soul", "Reality", "Mind"]
for i in range(n):
    ans[a.index(input())] = 1
print(ans.count(0))
for i in range(6):
    if ans[i] == 0:
        print(b[i])