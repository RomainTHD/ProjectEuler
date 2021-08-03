tempDict = {1: 1, 2: 2, 4: 3}

def f(n: int):
    val = tempDict.get(n, None)
    if val is None:
        if n % 2 == 0:
            return 1 + f(n // 2)
        else:
            return 1 + f(3*n + 1)
    else:
        return val

maxV = -1

for i in range(1, 10**6):
    v = f(i)
    if v > maxV:
        maxV = v
        print(i, v)
