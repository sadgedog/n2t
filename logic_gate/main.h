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
int test();
