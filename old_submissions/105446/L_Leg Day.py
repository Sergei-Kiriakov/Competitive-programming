import sys
sys.stdin.reconfigure(encoding='utf-8')
sys.stdout.reconfigure(encoding='utf-8')
n = int(input())
a = []
for i in range(n):
    s = input()
    if 'rest' in s:
        a.append(chr(128564))
    elif 'leg' in s:
        a.append(chr(129461))
    else:
        a.append(chr(128170))

for i in range(5):
    print(i+1, end=' ')
    for j in range(7):
        if i*7+j == 31:
            break
        print((a[(i*7+j)%n].encode("utf-8")).decode("utf-8"), end='')
    print()
