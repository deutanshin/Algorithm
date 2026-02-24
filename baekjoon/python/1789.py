S = int(input())

idx = 1

sum = 0
count = 0

while sum + idx <= S:
    sum += idx
    idx += 1
    count += 1

print(count)