#include "main.h"

int nand(int a, int b) {
  if (a >= 1 && b >= 1) {
    return 0;
  } else {
    return 1;
  }
}

int not(int in) {
  int out;
  out = nand(in, in);
  return out;
}

int and(int a, int b) {
  int w, out;
  w = nand(a, b);
  out = nand(w, w);
  return out;
}

int or(int a, int b) {
  int w1, w2, out;
  w1 = not(a);
  w2 = not(b);
  out = nand(w1, w2);
  return out;
}

int xor(int a, int b) {
  int nota, notb, w1, w2, out;
  nota = not(a);
  notb = not(b);
  w1 = and(a, notb);
  w2 = and(nota, b);
  out = or(w1, w2);
  return out;
}

int *not16(int in[16]) {
  int *out = malloc(sizeof(int) * 16);
  for (int i = 0; i < 16; i++)
    out[i] = nand(in[i], in[i]);
  return out;
}
