n = input()
count = 0
if len(n) == 1:
    print(9)
else:
    for i in range(1, len(n)):
        count += 10 - int(n[i]) - 1
    print(count + 10)