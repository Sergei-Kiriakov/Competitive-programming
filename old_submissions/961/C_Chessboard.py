n = int(input())
a1 = [[(i + n * j) % 2 for i in range(n)] for j in range(n)]
b1 = [[abs((i + n * j) % 2 - 1) for i in range(n)] for j in range(n)]
cell1 = [list(map(int, list(input()))) for i in range(n)]
l = input()
cell2 = [list(map(int, list(input()))) for i in range(n)]
l = input()
cell3 = [list(map(int, list(input()))) for i in range(n)]
l = input()
cell4 = [list(map(int, list(input()))) for i in range(n)]
count = [[0 , 0] for i in range(4)]
for i in range(n):
    for j in range(n):
        if cell1[i][j] != a1[i][j]:
            count[0][0] += 1
        if cell1[i][j] != b1[i][j]:
            count[0][1] += 1
        if cell2[i][j] != a1[i][j]:
            count[1][0] += 1
        if cell2[i][j] != b1[i][j]:
            count[1][1] += 1
        if cell3[i][j] != a1[i][j]:
            count[2][0] += 1
        if cell3[i][j] != b1[i][j]:
            count[2][1] += 1
        if cell4[i][j] != a1[i][j]:
            count[3][0] += 1
        if cell4[i][j] != b1[i][j]:
            count[3][1] += 1
min_1 = min(count[0][0] + count[1][0] + count[2][1] + count[3][1], count[0][0] + count[1][1] + count[2][0] + count[3][1], count[0][1] + count[1][0] + count[2][0] + count[3][1], count[0][0] + count[1][1] + count[2][1] + count[3][0], count[0][1] + count[1][0] + count[2][1] + count[3][0], count[0][1] + count[1][1] + count[2][0] + count[3][0])
print(min_1)