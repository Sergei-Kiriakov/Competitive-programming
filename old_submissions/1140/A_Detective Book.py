n = int(input())
count = 0
max_1 = 1
j = 0
a = list(map(int, input().split()))
while j < n:
    max_1 = max(max_1, a[j])
    while max_1 > j:
        max_1 = max(max_1, a[j])
        j += 1
    count += 1
print(count)