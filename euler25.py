#my solution for project euler 25(1000 digit fibonacci) https://projecteuler.net/problem=25
count = 3

fib1 = 1
fib2 = 1
current = fib1 + fib2

#generate the next fibonacci number, when it reaches 1000 digits stop
while len(str(current)) < 1000:
    fib1 = fib2
    fib2 = current
    current = fib1 + fib2
    count += 1

print(count)