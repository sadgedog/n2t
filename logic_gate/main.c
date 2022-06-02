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

  // 2 in 1 out
  for (int i = 0; i < 3; i++) {
    if (r_nand[i] != nand(l[i][0], l[i][1]))
      exit(1);
    if (r_and[i] != and(l[i][0], l[i][1]))
      exit(1);
    if (r_or[i] != or(l[i][0], l[i][1]))
      exit(1);
    if (r_xor[i] != xor(l[i][0], l[i][1]))
      exit(1);
  }
  printf("nand, and, or, xor OK\n");
  // 1 in 1 out
  for (int i = 0; i < 2; i++) {
    if (r_not[i] != not(ll[i]))
      exit(1);
  }
  printf("not OK\n");
  return 0
;
}
