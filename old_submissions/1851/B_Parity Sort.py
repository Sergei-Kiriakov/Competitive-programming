def solve():
    n = int(input())
    a = list(map(int, input().split()))
    b = sorted(a)
    c1 = list()
    c2 = list()
    for el in a:
        if el % 2 == 0:
            c1.append(el)
        else:
            c2.append(el)
    c1.sort()
    c2.sort()
    i = 0
    j = 0
    c = list()
    for el in a:
        if el % 2 == 0:
            c.append(c1[i])
            i += 1
        else:
            c.append(c2[j])
            j += 1
    if c == b:
        print("YES")
    else:
        print("NO")

def main():
    t = int(input())
    for i in range(t):
        solve()

main()
