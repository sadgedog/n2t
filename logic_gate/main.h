#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>

int nand(int a, int b);
int not(int in);
int and(int a, int b);
int or(int a, int b);
int xor(int a, int b);
int *not16(int in[16]);
int *or16(int a[16], int b[16]);
int *and16(int a[16], int b[16]);
int mux(int a, int b, int sel);
int *dmux(int in, int sel);
int *mux16(int a[16], int b[16], int sel);
int *mux4way16(int a[16], int b[16], int c[16], int d[16], int sel[2]);
int *mux8way16(int a[16], int b[16], int c[16], int d[16], int e[16], int f[16], int g[16], int h[16], int sel[3]);

int test();
