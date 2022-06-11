#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>

// pt.1
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
// pt.2
int *halfadder(int a, int b);
int *fulladder(int a, int b, int c);
int *add16(int a[16], int b[16]);
int *inc16(int in[16]);
int *alu(int a[16], int b[16], int zx, int nx, int zy, int ny, int f, int no);

typedef struct ALU ALU;

// test code
int test();

extern int l[4][2];
extern int ll[2];
extern int r_nand[4];
extern int r_not[4];
extern int r_and[4];
extern int r_or[4];
extern int r_xor[4];
extern int in_not16[4][16];
extern int r_not16[4][16];
extern int in_or16[12][16];
extern int r_or16[6][16];
extern int in_and16[12][16];
extern int r_and16[6][16];
extern int in_mux[8][3];
extern int r_mux[8];
extern int in_dmux[4][2];
extern int r_dmux[4][2];
extern int in_mux16[8][16];
extern int in_mux16_sel[8];
extern int r_mux16[8][16];
extern int in_mux4way16[4][16];
extern int in_mux4way16_sel[4][2];
extern int in_mux8way16[8][16];
extern int in_mux8way16_sel[8][3];
extern int in_halfadder[4][2];
extern int in_fulladder[8][3];
