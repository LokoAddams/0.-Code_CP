import sys
lines = sys.stdin.read().strip().split()

for i in range(0,len(lines), 3):
  b = int(lines[i])
  n = int(lines[i+1])
  m = int(lines[i+2])
  print(pow(b,n,m))