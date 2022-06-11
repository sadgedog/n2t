
#include "main.h"

// pt.1
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

int *or16(int a[16], int b[16]) {
  int *out = malloc(sizeof(int) * 16);
  for (int i = 0; i < 16; i++)
    out[i] = or(a[i], b[i]);
  return out;
}

int *and16(int a[16], int b[16]) {
  int *out = malloc(sizeof(int) * 16);
  for (int i = 0; i < 16; i++)
    out[i] = and(a[i], b[i]);
  return out;
}

int mux(int a, int b, int sel) {
  int notsel, w1, w2, out;
  notsel = not(sel);
  w1 = and(a, notsel);
  w2 = and(b, sel);
  out = or(w1, w2);
  return out;
}

int *dmux(int in, int sel) {
  int notsel;
  int *out = malloc(sizeof(int) * 2);
  notsel = not(sel);
  out[0] = and(in, notsel);
  out[1] = and(in, sel);
  return out;
}


// not tested from here
int *mux16(int a[16], int b[16], int sel) {
  int *out = malloc(sizeof(int) * 16);
  for (int i = 0; i < 16; i++)
    out[i] = mux(a[i], b[i], sel);
  return out;
}

int *mux4way16(int a[16], int b[16], int c[16], int d[16], int sel[2]) {
  int *w1 = malloc(sizeof(int) * 16);
  int *w2 = malloc(sizeof(int) * 16);
  int *out = malloc(sizeof(int) * 16);
  w1 = mux16(a, b, sel[0]);
  w2 = mux16(c, d, sel[0]);
  out = mux16(w1, w2, sel[1]);
  free(w1);
  free(w2);
  return out;
}

int *mux8way16(int a[16], int b[16], int c[16], int d[16], int e[16], int f[16], int g[16], int h[16], int sel[3]) {
  int *w1 = malloc(sizeof(int) * 16);
  int *w2 = malloc(sizeof(int) * 16);
  int *out = malloc(sizeof(int) * 16);
  int sel1[2] = {sel[2], sel[1]};
  w1 = mux4way16(a, b, c, d, sel1);
  w2 = mux4way16(e, f, g, h, sel1);
  out = mux16(w1, w2, sel[0]);
  free(w1);
  free(w2);
  return out;
}

// pt.2
int *halfadder(int a, int b) {
  int *out = malloc(sizeof(int) * 2);
  // out[0] = sum
  // out[1] = carry
  out[0] = xor(a, b);
  out[1] = and(a, b);
  return out;
}

int *fulladder(int a, int b, int c) {
  int *out = malloc(sizeof(int) * 2);
  // out[0] = sum
  // out[1] = carry
  int w1 = halfadder(a, b)[0];
  int w2 = halfadder(a, b)[1];
  out[0] = halfadder(w1, c)[0];
  int w3 = halfadder(w1, c)[1];
  out[1] = or(w2, w3);
  return out;
}
