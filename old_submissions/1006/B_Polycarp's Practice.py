n, k = map(int, input().split())
a = list(map(int, input().split()))
if k >= 2:
    cell_max = []
    cell_index = [-1]
    for i in range(k):
        max1 = 0
        index_max1 = 0    
        for j in range(n):
            if a[j] > max1:
                max1 = a[j]
                index_max1 = j
        a[index_max1] = 0
        cell_max.append(max1)
        cell_index.append(index_max1)
    print(sum(cell_max))
    cell_index = sorted(cell_index)
    ans = []
    for i in range(k - 1):
        ans.append(cell_index[i + 1] - cell_index[i])
    ans.append(n - cell_index[-2] - 1)
    print(" ".join(map(str, ans)))
else:
    print(max(a))
    print(n)