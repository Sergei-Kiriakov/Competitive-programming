def f(n):
    n = int(n)
    return (n ** 0.5 // 1) ** 2 == n


def g(n):
    max_len = 0
    last_cell = [0 for i in range(len(n))]
    cell1 = [1 for i in range(len(n))]
    cell = ""
    for i in range(2 ** 10):
        if last_cell == cell:
            break
        for j in range(len(n)):
            if last_cell[j] == 0:
                for h in range(j - 1, -1, -1):
                    last_cell[h] = 0
                last_cell[j] = 1
                break
        for j in range(len(n)):
            if last_cell[j] == 1:
                cell += (n[j])
        if f(cell) and len(cell) > max_len and cell[0] != "0":
            max_len = len(cell)
        cell = ""
    return len(n) - max_len 
    
n = list(input())
cell = g(n)
if cell == len(n):
    print(-1)
else:
    print(cell)