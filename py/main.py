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

def Or(a: bit, b: bit):
    w1 = Not(a)
    w2 = Not(b)
    out = Nand(w1, w2)
    return out

def Xor(a: bit, b: bit):
    nota = Not(a)
    notb = Not(b)
    w1 = And(a, notb)
    w2 = And(b, nota)
    out = Or(w1, w2)
    return out

def Not16(a: list):
    out = [bit.zero] * 16
    for i in range(16):
        out[i] = (Nand(a[i], a[i]))
    return out
