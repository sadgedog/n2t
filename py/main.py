from enum import IntFlag

# bit high or low
class bit(IntFlag):
    zero = 0,
    one = 1,

def nand(a: bit, b: bit):
    if a == 1 and b == 1:
        return bit.zero
    else:
        return bit.one
