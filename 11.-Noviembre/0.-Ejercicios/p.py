n = int(input())

while n:
  a , b = map(int, input().split())
  sa = str(a)
  sb = str(b)
  sa = sa[::-1]
  sb = sb[::-1]
  a = int(sa)
  b = int(sb)
  ans = a+ b
  sans = str(ans)
  print(int(sans[::-1]))
  n = n - 1
