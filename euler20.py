#my solution for project euler 20(factorial digit sum) https://projecteuler.net/problem=20
fac = 1
for i in range(1,101):
    fac *= i

temp = str(fac)
res = 0
for dig in temp:
    res += int(dig)

print(res)