def main():
    t = int(input())
    for i in range(t):
        x = input()
        y = input()
        i = -1
        count_y = 0
        while -i < len(y) and y[i] != "1":
            i -= 1
            count_y += 1
        i = -1
        ans = 0
        while -i < len(x) and (x[i] != "1" or -i <= count_y):
            i -= 1
            ans += 1
        print(max(ans - count_y, 0))
    
main()