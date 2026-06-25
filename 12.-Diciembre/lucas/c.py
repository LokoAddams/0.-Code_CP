import math as m
n = int(input())
a = [0]*(int(2e5+1))
vec = list(map(int,input().split()))
for i in range (0,n):
  a[vec[i]] += 1

ans = int()
for i in range (0,int(2e5+1)):
  if(a[i] > 1):
    ans += m.comb(a[i],2)*(n-a[i])
print(ans)
