def main():
    n = int(input())
    s = input()
    a = [0 for i in range(n)]
    for i in range(n):
        a[i] = ord(s[i]) - ord("a")
    flag = True
    count = 0
    while flag:
        n = len(a)
        flag = False
        ind = -1
        min1 = -1
        if n != 1:
            for i in range(n):
                if i == 0:
                    if a[i] - 1 == a[i + 1]:
                        if min1 < a[i]:
                            min1 = a[i]
                            flag = True
                            ind = i
                elif i == n - 1:
                    if a[i] - 1 == a[i - 1]:
                        if min1 < a[i]:
                            min1 = a[i]
                            flag = True
                            ind = i
                else:
                    if a[i] - 1 == a[i - 1] or a[i] - 1 == a[i + 1]:
                        if min1 < a[i]:
                            min1 = a[i]
                            flag = True
                            ind = i
        if ind != -1:
            a.pop(ind)
            count += 1
    print(count)

main()