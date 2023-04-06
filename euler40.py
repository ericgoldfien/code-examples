#my solution for project euler 40(champernownes constant) https://projecteuler.net/problem=40
champ = ''

#create champernownes constant
for i in range(1000001):
    champ = champ + str(i)

res = int(champ[1]) * int(champ[10]) * int(champ[100]) * int(champ[1000]) * int(champ[10000]) * int(champ[100000]) * int(champ[1000000])
print(res)