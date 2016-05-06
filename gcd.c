#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void extendGcdCalc(int*, int*, int*, int, int);

int main(int argc, char **argv) {
  int eFlag = 0, testFlag = 0;
  int first, second;
  char c;

  while ((c = getopt(argc, argv, "et")) != -1) {
    if (c == 'e') eFlag = 1;
    if (c == 't') testFlag = 1;
  }

  if (testFlag) {
    eFlag = 1;
    first = 163231;
    second = 135749;
  } else {
    first = strtol(argv[optind], NULL, 10);
    second = strtol(argv[optind + 1], NULL, 10);
  }

  int *u, *v, *gcd;
  u = (int*) malloc(sizeof(int));
  v = (int*) malloc(sizeof(int));
  gcd = (int*) malloc(sizeof(int));

  extendGcdCalc(u, v, gcd, first, second);

  printf("the greatest common denominator is %d.\n", *gcd);

  if (eFlag) {
    printf("u * %d + v * %d = %d.\n", first, second, *gcd);
    printf("where u = %d and v = %d.\n", *u, *v);
  }
  
  return 0;
}

void extendGcdCalc(int *coefFirst, int *coefSecond, int *gcd, int first, int second) {
  int u = 1;
  int g = first;
  int x = 0;
  int y = second;
  int s1, s2;

  while (y) {
    s1 = u - (g / y) * x;
    s2 = g % y;
    u = x;
    g = y;
    x = s1;
    y = s2;
  }

  *coefFirst = u;
  *coefSecond = (g - first * u) / second;
  *gcd = g;

  return;
}
