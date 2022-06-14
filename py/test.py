from main import (
    bit,
    nand,
)
from value import (
    two_in,
)

def test():
    # nand test
    for i in range(4):
        res = int(nand(two_in[i][0], two_in[i][1]))
        print(res)


def main():
    test()
    return 0


if __name__ == '__main__':
    main()
