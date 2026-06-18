s = input().replace(",", ";").split(";")
ans1 = []
ans2 = []
for elem in s:
    try:
        if (str(int(elem)) == elem):
            ans1.append(elem)
        else:
            ans2.append(elem)
    except:
        ans2.append(elem)

if (ans1 == []):
    print("-")
else:
    print('"', end="")   
    print(*ans1, sep=",", end="")
    print('"')
if (ans2 == []):
    print("-")
else:
    print('"', end="")
    print(*ans2, sep=",", end="")
    print('"')