import typing


def getNthTriangle(n: int) -> int:
    return sum(range(n + 1))


def getDivisors(n: int) -> typing.List[int]:
    div = [1, 2] if n % 2 == 0 else [1]

    for i in range(3, n // 2 + 1):
        if n % i == 0:
            div.append(i)

    div.append(n)

    return div


if __name__ == "__main__":
    n = 1

    while True:
        div = getDivisors(getNthTriangle(n))

        if len(div) > 500:
            print(div)
            print(getNthTriangle(n))
            print(n)
            break

        n += 1
