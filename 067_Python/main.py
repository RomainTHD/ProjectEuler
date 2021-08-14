import typing


class Element:
    row: int
    col: int
    ownValue: int
    sumValue: int
    parent: typing.Optional["Element"]

    def __init__(self, row: int, col: int, ownValue: int, parent: typing.Optional["Element"]):
        self.row = row
        self.col = col
        self.ownValue = ownValue
        self.sumValue = ownValue
        self.parent = parent

        if self.parent is not None:
            self.sumValue += self.parent.sumValue


def loadData() -> typing.List[typing.List[int]]:
    data: typing.List[typing.List[int]] = []

    f = open("triangle.txt")
    lines: typing.List[str] = f.readlines()
    f.close()

    for line in lines:
        numbers: typing.List[str] = line.split(' ')
        row: typing.List[int] = []

        for number in numbers:
            row.append(int(number))

        data.append(row)

    return data


def isValidPosition(row: int, col: int) -> bool:
    return 0 <= col <= row


def processData(data: typing.List[typing.List[int]]) -> typing.List[typing.List[Element]]:
    res: typing.List[typing.List[Element]] = [[Element(0, 0, data[0][0], None)]]

    for row in range(1, len(data)):
        resRow: typing.List[Element] = []

        for col in range(len(data[row])):
            parent: typing.Optional[Element] = None

            for diff in (-1, 0):
                if isValidPosition(row - 1, col + diff):
                    checkedParent = res[row - 1][col + diff]
                    if parent is None or parent.sumValue < checkedParent.sumValue:
                        parent = checkedParent

            resRow.append(Element(row, col, data[row][col], parent))

        res.append(resRow)

    return res


def printSolution(res: typing.List[typing.List[Element]]) -> None:
    bestElement: typing.Optional[Element] = None
    for elt in res[-1]:
        if bestElement is None or elt.sumValue > bestElement.sumValue:
            bestElement = elt

    s = ""

    parent = bestElement
    while parent is not None:
        s = f'{"." * parent.col}@{"." * (parent.row - parent.col)}\n' + s
        parent = parent.parent

    print(s)
    print(bestElement.sumValue)


def main():
    data = loadData()
    res = processData(data)
    printSolution(res)


if __name__ == "__main__":
    main()
