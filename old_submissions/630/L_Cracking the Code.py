n = input()
n1 = int(n[0] + n[2] + n[4] + n[3] + n[1])
ans = str(n1 ** 5 % 100000)
print('0' * (5 - len(ans)) + ans)