import sys
from math import gcd
def lcm(a, b):
    return a*b//gcd(a, b)

def sum_drobs(p1, p2):
    left_x, left_y = p1
    right_x, right_y = p2
    lcm_y = lcm(left_y, right_y)
    sum_x = left_x*(lcm_y//left_y) + right_x*(lcm_y//right_y)
    gcd_x_y = gcd(sum_x, lcm_y)
    return (sum_x//gcd_x_y, lcm_y//gcd_x_y)

def solve():
    n = int(input())
    points  = []
    for i  in range(n):
        x, y = map(int, input().split())
        points.append(x)
    
    points.sort()
    if (len(points)==len(set(points))):
        u, v = 0, 1
        p, q = 0, 1
        for i in range(1, n):
            prev_x = points[i-1]
            x = points[i]
            if i < n-1:
                print(f"? {x} 1")
                sys.stdout.flush()
                new_p, new_q = map(int, input().split())
            else:
                new_p, new_q = 0, 1
            sum_lengths = sum_drobs((p, q), (new_p, new_q))
            chisl, znam = sum_lengths
            dist = x - prev_x
            part_square = (chisl*dist, znam*2)
            curr_square = (u, v)
            u, v = sum_drobs(part_square, curr_square)
            p, q  = new_p, new_q
        gcd_u_v = gcd(u, v)
        print(f"! {u//gcd_u_v} {v//gcd_u_v}")
        sys.stdout.flush()
    else:
        u, v = 0, 1
        p, q = 0, 1
        for i in range(1, n):
            prev_x = points[i-1]
            x = points[i]
            if (x==prev_x):
                continue
            print(f"? {x+prev_x} 2")
            sys.stdout.flush()
            new_p, new_q = map(int, input().split())
            length = (new_p, new_q)
            chisl, znam = length
            dist = x - prev_x
            part_square = (chisl*dist, znam)
            curr_square = (u, v)
            u, v = sum_drobs(part_square, curr_square)
            p, q  = new_p, new_q
        gcd_u_v = gcd(u, v)
        print(f"! {u//gcd_u_v} {v//gcd_u_v}")
        sys.stdout.flush()

t = int(input())
for it in range(t):
    solve()