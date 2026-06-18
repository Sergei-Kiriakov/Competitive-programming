def f(n):
   i = 2
   primfac = []
   while i * i <= n:
      if n % i == 0:
         primfac.append([i, 0])
         while n % i == 0:
            primfac[-1][1] += 1
            n //= i
      i += 1
   if n > 1:
      primfac.append([n, 1])
   return primfac

def main():
   n, b1 = map(int, input().split())
   ans = f(b1)
   min_count = 10 ** 18 + 1
   for j in range(len(ans)):
      b = ans[j][0]
      count = 0
      flag = True
      i = 1
      while flag:
         flag = False
         c = n // pow(b, i)
         if c != 0:
            flag = True
         count += c
         i += 1
      min_count = min(count // ans[j][1], min_count)
   print(min_count)   
    
main()
