n = int(input())
ans = 1
for i in range(11):
    ans *= n-i-1
for i in range(11):
    ans //= i+1
print(ans)
