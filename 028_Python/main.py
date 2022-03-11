size = 1001

accumulator = 0
diff = 2
turnCount = 0

n = 1
while n <= size * size + 1:
    accumulator += n
    n += diff
    turnCount += 1
    if turnCount == 4:
        turnCount = 0
        diff += 2

print(accumulator)
