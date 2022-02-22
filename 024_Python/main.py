import math
import typing


class PermutationItem:
    def __init__(
            self,
            value: int,
            size: int,
            children: typing.Generator["PermutationItem", None, None] = None
    ):
        self.value = value
        self.size = size
        self.children = children


def getPerms(value: typing.Optional[int], nbs: list[int]) -> PermutationItem:
    if len(nbs) == 0:
        return PermutationItem(value, 1, None)
    else:
        # Lazy evaluation using generators
        return PermutationItem(
            value,
            math.factorial(len(nbs)),
            (
                getPerms(nbs[i], nbs[:i] + nbs[i + 1:])
                for i in range(len(nbs))
            )
        )


def getNthPerm(n: typing.Union[int, float], b: int) -> str:
    n += 1
    root = getPerms(None, list(range(b + 1)))

    if n >= root.size:
        raise IndexError("Not enough permutations, n is too large")

    res = []

    while root.children is not None:
        for child in root.children:
            if n in range(child.size):
                root = child
                res.append(child.value)
                break
            else:
                n -= child.size

    return "".join(map(str, res))


print(getNthPerm(1e6, 9))
