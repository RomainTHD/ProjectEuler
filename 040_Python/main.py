import math

i = 1
n = 0
res = 1
maxDigitCount = 1

while True:
    i_tmp = i

    while i_tmp != 0:
        digitCount = int(math.log(i_tmp, 10)) + 1
        digit = int(i_tmp / 10 ** (digitCount - 1))
        i_tmp -= digit * 10 ** (digitCount - 1)
        n += 1

        print(digit)

        if n % 10 ** maxDigitCount == 0:
            # print(n, digit)
            maxDigitCount += 1
            res *= digit

    i_tmp = i
    while i_tmp % 10 == 0:
        n += 1
        i_tmp //= 10
        print(0)

    i += 1

    if n >= 1000 or n >= 1_000_000:
        break

print(res)

# FIXME: 101 to 109
