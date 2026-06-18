def main():
    t = int(input())
    for i in range(t):
        a, b, n = map(int, input().split())
        s1 = list(bin(a)[2:])
        s2 = list(bin(b)[2:])        
        ans = 0
        prod = 1
        s3 = [0 for i in range(max(len(s1), len(s2)))]
        for i in range(max(len(s1), len(s2))):
            if i < len(s1) and i < len(s2):
                if s1[-i - 1] == "1" and s2[-i - 1] == "1":
                    s3[-i - 1] = 0
                if s1[-i - 1] == "0" and s2[-i - 1] == "1":
                    s3[-i - 1] = 1
                if s1[-i - 1] == "1" and s2[-i - 1] == "0":
                    s3[-i - 1] = 1
                if s1[-i - 1] == "0" and s2[-i - 1] == "0":
                    s3[-i - 1] = 0 
            else:
                if i < len(s1):
                    s3[-i - 1] = int(s1[-i - 1])   
                else:
                    s3[-i - 1] = int(s2[-i - 1])
        for i in range(len(s3) - 1, -1, -1):
            if s3[i] == 1:
                ans += prod
            prod *= 2   
        if n % 3 == 0:
            print(a)
        elif n % 3 == 1:
            print(b)
        else:
            print(ans)
                
main()