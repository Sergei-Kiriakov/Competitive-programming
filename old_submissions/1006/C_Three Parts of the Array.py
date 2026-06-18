n = int(input())
a = list(map(int, input().split()))
sum4 = sum(a)
sum1 = 0
sum3 = 0
ans = 0
left = 0
right = n - 1
while sum1 + sum3 <= sum4:
    if sum3 > sum1:
        sum1 += a[left]
        left += 1
    elif sum1 > sum3:
        sum3 += a[right]
        right -= 1
    else:
        ans = sum1
        sum1 += a[left]
        sum3 += a[right]
        right -= 1
        left += 1
print(ans)