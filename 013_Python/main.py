sum = 0

f = open("numbers.txt")

for i in range(100):
    sum += int(f.readline().rstrip())

f.close()

print(str(sum)[:10])
