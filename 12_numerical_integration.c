#include <math.h>
#include <stdio.h>

int main() {
  int n = 18;
  double a = 0, b = 1, h = (b - a) / n, s = 0, x;
  // here we are using the standard intuitive definition of integrals as area
  // under curve if you dont understand this simple code please kys
  for (int i = 0; i < n; i++) {
    x = a + h * (i + 0.5);
    s += sqrt(sin(x) + cos(x));
  }
  printf("%f\n", s * h);
  return 0;
}