#include <stdlib.h>
#include <stdio.h>
#include "main.h"
int test();

int main() {
  test();
}


int test() {
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
    int *res = not16(in_not16[i]);
    for (int k = 0; k < 16; k ++) {
      printf("%d", res[k]);
    }
    printf("\n");
  }
  int *a;
  for (int i = 0; i < 4; i++) {
    a = not16(in_not16[i]);
    if (memcmp(a, r_not16[i], 16 * sizeof(int)) != 0) {
      printf("NG\n");
      exit(1);
    } 
  }
  
  printf("ALL CONFIRMED\n");
  return 0;
}
