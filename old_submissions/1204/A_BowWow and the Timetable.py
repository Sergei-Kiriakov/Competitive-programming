def main():
    n = input()
    flag = True
    for i in range(1, len(n)):
        if n[i] == "1":
            flag = False
    if flag:
        print((len(n)) // 2)
    else:
        print((len(n) + 1) // 2)

main()