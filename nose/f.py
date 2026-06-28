import sys
data = sys.stdin.read().split()
t = int(data[0])
cont = 1
for _ in range(t):
  n = int(data[cont])
  cont += 1
  nums = list(map(int, data[cont: cont+n]))
  print(sum(nums))
  cont += n