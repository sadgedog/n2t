from main import (
    Nand,
    Not,
    And,
    Or,
    Xor,
    Not16,
)
from value import (
    two_in,
    one_in,
    in_not16,
    in_or16,
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
        r = check(res, ref)
        if (r):
            print(ref, "=>", res)
        else:
            exit(1)
    # and
    print("AND")
    for i in range(4):
        res = int(And(two_in[i][0], two_in[i][1]))
        ref = int((two_in[i][0] and two_in[i][1]))
        r = check(res, ref)
        if (r):
            print(ref, "=>", res)

    # or
    print("OR")
    for i in range(4):
        res = int(Or(two_in[i][0], two_in[i][1]))
        ref = int((two_in[i][0] or two_in[i][1]))
        r = check(res, ref)
        if (r):
            print(ref, "=>", res)
        else:
            exit(1)

    # xor
    print("XOR")
    for i in range(4):
        res = int(Xor(two_in[i][0], two_in[i][1]))
        ref = int((two_in[i][0] ^ two_in[i][1]))
        r = check(res, ref)
        if (r):
            print(ref, "=>", res)
        else:
            exit(1)

    # or16
    print("Not16")
    for i in range(4):
        res = (Not16(in_not16[i]))
        for j in range(16):
            res[j] = int(res[j])
        print(res)
        
def check(a, b):
    return a == b
        
def main():
    test()    
    return 0


if __name__ == '__main__':
    main()
