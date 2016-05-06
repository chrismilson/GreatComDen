#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void extendGcdCalc(int*, int*, int*, int, int);

int main(int argc, char **argv) {
  int eFlag = 0;


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
