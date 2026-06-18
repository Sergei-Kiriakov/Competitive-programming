from math import sqrt
l1, l2, l3 = map(int, input().split())
s1 = l1 * l1 * l1 / sqrt(72)
s2 = l2 * l2 * l2 / (3 * sqrt(2))
s3 = l3 * l3 * l3 * (5 + sqrt(5)) / 24
print(s1 + s2 + s3)