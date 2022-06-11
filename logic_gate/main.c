#include <stdlib.h>
#include <stdio.h>
#include "main.h"
int l[4][2] = {{0, 0}, {1, 0}, {0, 1}, {1, 1}};
int ll[2] = {0, 1};
int r_nand[4] = {1, 1, 1, 0};
int r_not[4] = {1, 0};
int r_and[4] = {0, 0, 0, 1};
int r_or[4] = {0, 1, 1, 1};
int r_xor[4] = {0, 1, 1, 0};

int in_not16[4][16] = {{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                       {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                       {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},
                       {0,0,0,1,0,0,1,0,0,0,1,1,0,1,0,0}};
int r_not16[4][16] = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                      {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                      {0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
                      {1,1,1,0,1,1,0,1,1,1,0,0,1,0,1,1}};

int in_or16[12][16] = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},

                       {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                       {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},

                       {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                       {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},

                       {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},
                       {0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},

                       {0,0,1,1,1,1,0,0,1,1,0,0,0,0,1,1},
                       {0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0},

                       {0,0,0,1,0,0,1,0,0,0,1,1,0,1,0,0},
                       {1,0,0,1,1,0,0,0,0,1,1,1,0,1,1,0}};

int r_or16[6][16] = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                     {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                     {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                     {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                     {0,0,1,1,1,1,1,1,1,1,1,1,0,0,1,1},
                     {1,0,0,1,1,0,1,0,0,1,1,1,0,1,1,0}};

int in_and16[12][16] = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},

                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},

                        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},

                        {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},
                        {0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},

                        {0,0,1,1,1,1,0,0,1,1,0,0,0,0,1,1},
                        {0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0},

                        {0,0,0,1,0,0,1,0,0,0,1,1,0,1,0,0},
                        {1,0,0,1,1,0,0,0,0,1,1,1,0,1,1,0}};
  
int r_and16[6][16] = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                      {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                      {0,0,0,0,1,1,0,0,1,1,0,0,0,0,0,0},
                      {0,0,0,1,0,0,0,0,0,0,1,1,0,1,0,0}};

int in_mux[8][3] = {{0,0,0},{0,0,1},{0,1,0},{0,1,1},{1,0,0},{1,0,1},{1,1,0},{1,1,1}};
int r_mux[8] = {0,0,0,1,1,0,1,1};

int in_dmux[4][2] = {{0,0},{0,1},{1,0},{1,1}};
int r_dmux[4][2] = {{0,0},{0,0},{1,0},{0,1}};

int in_mux16[8][16] = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                       {0,0,0,1,0,0,1,0,0,0,1,1,0,1,0,0},
                       {1,0,0,1,1,0,0,0,0,1,1,1,0,1,1,0},
                       {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                       {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},
                       {0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1}};
int in_mux16_sel[8] = {0,1,0,1,0,1,0,1};
int r_mux16[8][16] = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                      {0,0,0,1,0,0,1,0,0,0,1,1,0,1,0,0},
                      {1,0,0,1,1,0,0,0,0,1,1,1,0,1,1,0},
                      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                      {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},
                      {0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1}};

int in_mux4way16[4][16] = {{0,0,0,1,0,0,1,0,0,0,1,1,0,1,0,0},
                           {1,0,0,1,1,0,0,0,0,1,1,1,0,1,1,0},
                           {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},
                           {0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1}};
int in_mux4way16_sel[4][2] = {{0,0},{0,1},{1,0},{1,1}};

int in_mux8way16[8][16] = {{0,0,0,1,0,0,1,0,0,0,1,1,0,1,0,0},
                           {0,0,1,0,0,0,1,1,0,1,0,0,0,1,0,1},
                           {0,0,1,1,0,1,0,0,0,1,0,1,0,1,1,0},
                           {0,1,0,0,0,1,0,1,0,1,1,0,0,1,1,1},
                           {0,1,0,1,0,1,1,0,0,1,1,1,1,0,0,0},
                           {0,1,1,0,0,1,1,1,1,0,0,0,1,0,0,1},
                           {0,1,1,1,1,0,0,0,1,0,0,1,1,0,1,0},
                           {1,0,0,0,1,0,0,1,1,0,1,0,1,0,1,1}};
int in_mux8way16_sel[8][3] = {{0,0,0},{0,0,1},{0,1,0},{0,1,1},
                              {1,0,0},{1,0,1},{1,1,0},{1,1,1}};

int in_halfadder[4][2] = {{0,0},{0,1},{1,0},{1,1}};

int in_fulladder[8][3] = {{0,0,0},{0,0,1},{0,1,0},{0,1,1},
                          {1,0,0},{1,0,1},{1,1,0},{1,1,1}};


int main() {
  test();
}


int test() {
  printf("NAND\n");
  for (int i = 0; i < 4; i++) {
    printf("{%d, %d} => %d\n", l[i][0], l[i][1], nand(l[i][0], l[i][1]));
  }
  printf("NOT\n");
  for (int i = 0; i < 2; i++) {
    printf("{%d} => %d\n", ll[i], not(ll[i]));
  }
  printf("AND\n");
  for (int i = 0; i < 4; i++) {
    printf("{%d, %d} => %d\n", l[i][0], l[i][1], and(l[i][0], l[i][1]));
  }
  printf("OR\n");
  for (int i = 0; i < 4; i++) {
    printf("{%d, %d} => %d\n", l[i][0], l[i][1], or(l[i][0], l[i][1]));
  }
  printf("XOR\n");
  for (int i = 0; i < 4; i++) {
    printf("{%d, %d} => %d\n", l[i][0], l[i][1], xor(l[i][0], l[i][1]));
  }
  
  // 2 in 1 out
  for (int i = 0; i < 4; i++) {
    if (r_nand[i] != nand(l[i][0], l[i][1]))
      exit(1);
    if (r_and[i] != and(l[i][0], l[i][1]))
      exit(1);
    if (r_or[i] != or(l[i][0], l[i][1]))
      exit(1);
    if (r_xor[i] != xor(l[i][0], l[i][1]))
      exit(1);
  } 
  // 1 in 1 out
  for (int i = 0; i < 2; i++) {
    if (r_not[i] != not(ll[i]))
      exit(1);
  }

  // NOT16
  printf("NOT16\n");
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 16; j++) {
      printf("%d", in_not16[i][j]);
    }
    printf(" => ");
    int *res_not16 = not16(in_not16[i]);
    for (int k = 0; k < 16; k ++) {
      printf("%d", res_not16[k]);
    }
    printf("\n");
  }
  int *res_not16;
  for (int i = 0; i < 4; i++) {
    res_not16 = not16(in_not16[i]);
    if (memcmp(res_not16, r_not16[i], 16 * sizeof(int)) != 0) {
      printf("NG\n");
      exit(1);
    } 
  }
  free(res_not16);
  
  // OR16
  printf("OR16\n");
  for (int i = 0; i < 6; i++) {
    printf("{");
    for (int j = 0; j < 16; j++) {
      printf("%d", in_or16[2*i][j]);
    }
    printf(", ");
    for (int j = 0; j < 16; j++) {
      printf("%d", in_or16[2*i+1][j]);
    }
    printf("}");
    printf(" => ");
    int *res_or16 = or16(in_or16[i*2], in_or16[2*i+1]);
    for (int k = 0; k < 16; k ++) {
      printf("%d", res_or16[k]);
    }
    printf("\n");
  }
  int *res_or16;
  for (int i = 0; i < 6; i++) {
    res_or16 = or16(in_or16[2*i], in_or16[2*i+1]);
    if (memcmp(res_or16, r_or16[i], 16 * sizeof(int)) != 0) {
      printf("NG\n");
      exit(1);
    }
  }
  free(res_or16);

  // AND16
  printf("AND16\n");
  for (int i = 0; i < 6; i++) {
    printf("{");
    for (int j = 0; j < 16; j++) {
      printf("%d", in_and16[2*i][j]);
    }
    printf(", ");
    for (int j = 0; j < 16; j++) {
      printf("%d", in_and16[2*i+1][j]);
    }
    printf("}");
    printf(" => ");
    int *res_and16 = and16(in_and16[i*2], in_and16[2*i+1]);
    for (int k = 0; k < 16; k ++) {
      printf("%d", res_and16[k]);
    }
    printf("\n");
  }
  int *res_and16;
  for (int i = 0; i < 6; i++) {
    res_and16 = and16(in_and16[2*i], in_and16[2*i+1]);
    if (memcmp(res_and16, r_and16[i], 16 * sizeof(int)) != 0) {
      printf("NG\n");
      exit(1);
    }
  }
  free(res_and16);

  // MUX
  printf("MUX\n");
  for (int i = 0; i < 8; i++) {
    int r;
    r = mux(in_mux[i][0], in_mux[i][1], in_mux[i][2]);
    printf("{%d, %d, %d} => %d\n", in_mux[i][0], in_mux[i][1], in_mux[i][2], r);
    if (r != r_mux[i]) {
      printf("NG");
      exit(1);
    }
  }

  // DMUX
  printf("DMUX\n");
  int *res_dmux;
  for (int i = 0; i < 4; i ++) {
    res_dmux = dmux(in_dmux[i][0], in_dmux[i][1]);
    printf("{%d %d} => {%d, %d}", r_dmux[i][0], r_dmux[i][1], res_dmux[0], res_dmux[1]);
    printf("\n");
    if (memcmp(res_dmux,  r_dmux[i], 2 * sizeof(int)) != 0) {
      printf("NG\n");
      exit(1);
    }
  }
  free(res_dmux);

  // 以下テスト簡略化
  // MUX16
  //| 0000000000000000 | 0001001000110100 |  0  | 0000000000000000 |            
  //| 0000000000000000 | 0001001000110100 |  1  | 0001001000110100 |
  printf("MUX16\n");
  int *res_mux16;
  res_mux16 = mux16(in_mux16[2], in_mux16[3], in_mux16_sel[0]);
  for (int i = 0; i < 16; i++) {
    printf("%d", res_mux16[i]);
  }
  printf("\n");
  res_mux16 = mux16(in_mux16[2], in_mux16[3], in_mux16_sel[1]);
  for (int i = 0; i < 16; i++) {
    printf("%d", res_mux16[i]);
  }
  printf("\n");
  free(res_mux16);
  
  // MUX4WAY16
  printf("MUX4WAY16\n");
  int *res_mux4way16;
  for (int i = 0; i < 4; i++) {
    res_mux4way16 = mux4way16(in_mux4way16[0],
                              in_mux4way16[1],
                              in_mux4way16[2],
                              in_mux4way16[3],
                              in_mux4way16_sel[i]);  
    for (int j = 0; j < 16; j ++) {
      printf("%d", res_mux4way16[j]);
    }
    printf("\n");
  }
  free(res_mux4way16);
  
  // MUX8WAY16
  printf("MUX8WAY16\n");
  int *res_mux8way16;
  for(int i = 0; i < 8; i++) {
    res_mux8way16 = mux8way16(in_mux8way16[0],
                              in_mux8way16[1],
                              in_mux8way16[2],
                              in_mux8way16[3],
                              in_mux8way16[4],
                              in_mux8way16[5],
                              in_mux8way16[6],
                              in_mux8way16[7],
                              in_mux8way16_sel[i]);
    for (int j = 0; j < 16; j++) {
      printf("%d", res_mux8way16[j]);
    }
    printf("\n");
  }
  free(res_mux8way16);


  // pt.2
  // HalfAdder
  printf("HalfAdder\n");
  int *res_halfadder;
  for (int i = 0; i < 4; i++) {
    res_halfadder = halfadder(in_halfadder[i][0],
                              in_halfadder[i][1]);
    printf("{%d, %d} => carry:%d sum:%d\n",
           in_halfadder[i][0], in_halfadder[i][1],
           res_halfadder[1], res_halfadder[0]);
  }
  free(res_halfadder);

  // FullAdder
  printf("FullAdder\n");
  int *res_fulladder;
  for (int i = 0; i < 8; i++) {
    res_fulladder = fulladder(in_fulladder[i][0],
                              in_fulladder[i][1],
                              in_fulladder[i][2]);
    printf("{%d, %d, %d} => carry:%d sum:%d\n",
           in_fulladder[i][0], in_fulladder[i][1], in_fulladder[i][2],
           res_fulladder[1], res_fulladder[0]);
  }
  // Incrementor
  printf("Incrementor\n");

  // ALU
  printf("ALU\n");

  
  // pt.3

  
  printf("ALL CONFIRMED\n");
  return 0;
}
