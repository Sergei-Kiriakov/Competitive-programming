n, a, b = map(int, input().split())
s = list(input())
count = 0
for i in range(n):
    if s[i] == ".":
        if i - 1 >= 0:
            if s[i - 1] == "A" and b > 0:
                count += 1
                s[i] = "B"
                b -= 1
            elif s[i - 1] == "B" and a > 0:
                count += 1
                s[i] = "A"
                a -= 1
            elif s[i - 1] == "*" or s[i - 1] == ".":
                if a >= b and a > 0:
                    count += 1
                    s[i] = "A"
                    a -= 1
                elif b > a and b > 0:
                    count += 1
                    s[i] = "B"
                    b -= 1
        else:
            if a >= b and a > 0:
                count += 1
                s[i] = "A"
                a -= 1
            elif b > a and b > 0:
                count += 1
                s[i] = "B"
                b -= 1            
print(count)