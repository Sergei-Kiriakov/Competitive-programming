n = int(input())
s = input()
if s.count("1") > 0:
    print("1" + "0" * s.count("0"))
else:
    print("0")