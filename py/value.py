from main import (
    bit,
)

z = bit.zero
i = bit.one

two_in = [[z, z], [z, i], [i, z], [i, i]]
one_in = [z, i]

in_not16 = [[i]*16,[z]*16,
            [i,z,i,z,i,z,i,z,i,z,i,z,i,z,i,z],
            [z,z,z,i,z,z,i,z,z,z,i,i,z,i,z,z]]

in_or16 = [[z]*16,[z]*16,
           [z]*16, [i]*16,
           [i]*16, [i]*16,
           [i,z,i,z,i,z,i,z,i,z,i,z,i,z,i,z],
           [z,i,z,i,z,i,z,i,z,i,z,i,z,i,z,i],
           [z,z,i,i,i,i,z,z,i,i,z,z,z,z,i,i],
           [z,z,z,z,i,i,i,i,i,i,i,i,z,z,z,z],
           [z,z,z,i,z,z,i,z,z,z,i,i,z,i,z,z],
           [i,z,z,i,i,z,z,z,z,i,i,i,z,i,i,z]]
