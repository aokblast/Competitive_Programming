import math
n = int(input())
a = 0

for b in range(n + 1, int(1e6)):
    if((n * b) % (b - n) == 0):
        a = max(a, (math.floor(n * b / (b - n)) ^ b))

print(a)
