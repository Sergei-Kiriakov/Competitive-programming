n, k = map(int, input().split())
a = list(map(int, input().split()))
t = list(map(int, input().split()))
left = 0
right = 0
count_c = 0
count_max = 0
for left in range(n):
    if left > 0 and t[left - 1] == 0:
        count_c -= a[left - 1]    
    if t[left] == 0:
        while right < n and right - left < k:
            if t[right] == 0:
                count_c += a[right]
            right += 1
    count_max = max(count_c, count_max)
    left += 1
count = 0
for i in range(n):
    if t[i] == 1:
        count += a[i]
print(count + count_max)