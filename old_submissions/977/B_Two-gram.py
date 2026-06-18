n = int(input())
s = input()
cell = []
ans = []
for i in range(1, n):
    for j in range(1, n):
        if s[i - 1:i + 1] == s[j - 1:j + 1]:
            if s[i - 1:i + 1] in cell:
                ans[cell.index(s[i - 1:i + 1])] += 1
            else:
                cell.append(s[i - 1:i + 1])
                ans.append(1)
print(cell[ans.index(max(ans))])