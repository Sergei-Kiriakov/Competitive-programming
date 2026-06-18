from math import sin, pi
 
n, r = map(int, input().split())
al = 2 * pi / n
ga = 3 * al / 2
be = (pi - al) / 2
be1 = (pi - ga) / 2
sin_al = sin(al)
sin_be = sin(be)
sin_ga = sin(ga)
sin_be1 = sin(be1)
AB = sin_al * r / sin_be
O1B = AB * sin_be1 / sin_ga
print(n * (sin_al * r * r / 2 - O1B * O1B * sin_ga / 2))