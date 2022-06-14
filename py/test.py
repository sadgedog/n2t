from main import (
    Nand,
    Not,
    And,
)
from value import (
    two_in,
    one_in,
)

def test():
    # nand
    print("NAND")
    for i in range(4):
        res = int(Nand(two_in[i][0], two_in[i][1]))
        ref = int(not(two_in[i][0] & two_in[i][1]))
        r = check(res, ref)
        if (r):
            print(ref, "=>", res)
        else:
            exit(1)
    # not
    print("NOT")
    for i in range(2):
        res = int(Not(one_in[i]))
        ref = int(not(one_in[i]))
        if (r):
            print(ref, "=>", res)
        else:
            exit(1)
    # and
    print("AND")
    for i in range(4):
        res = int(And(two_in[i][0], two_in[i][1]))
        ref = int((two_in[i][0] and two_in[i][1]))
        if (r):
            print(ref, "=>", res)

def check(a, b):
    return a == b
        
def main():
    test()
    
    return 0


if __name__ == '__main__':
    main()
