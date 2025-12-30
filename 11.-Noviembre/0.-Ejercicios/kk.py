import math
n,r = map(int, input().split())
while n != 0 and r != 0:
  print(n , "things taken",r, "at a time is",math.comb(n, r) , "exactly.")
  n,r = map(int, input().split())