def main():
    n, l, r = map(int, input().split())
    sum1 = 0
    sum2 = 0
    for i in range(r):
        sum1 += pow(2, i)
    for i in range(l):
        sum2 += pow(2, i)
    print(sum2 + (n - l), sum1 + (n - r) * pow(2, r - 1))

main()