from enum import IntFlag

# bit high or low
class bit(IntFlag):
    zero = 0,
    one = 1,

def Nand(a: bit, b: bit):
    if a == 1 and b == 1:
        return bit.zero
    else:
        return bit.one

def Not(a: bit):
    out = Nand(a, a)
    return out

def And(a: bit, b: bit):
    w = Nand(a, b)
    out = Nand(w, w)
    return out
