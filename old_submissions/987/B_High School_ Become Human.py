def main():
    x, y = map(int, input().split())
    if x > 2 and y > 2:
        if x > y:
            print("<")
        elif y > x:
            print(">")
        else:
            print("=")
    elif x == 2 and y > 4:
        print(">")
    elif y == 2 and x > 4:
        print("<")
    else:
        a = pow(x, y)
        b = pow(y, x)
        if a > b:
            print(">")
        elif b > a:
            print("<")
        else:
            print("=")

main()