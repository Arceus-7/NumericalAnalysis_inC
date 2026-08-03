#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

double f(double x) { return sqrt(sin(x) + cos(x)); }

int main() {
  int n, mode;
  double a, b;

  printf("Enter limits as (1) real numbers or (2) degrees: ");
  scanf("%d", &mode);
  printf("Enter lower limit a: ");
  scanf("%lf", &a);
  printf("Enter upper limit b: ");
  scanf("%lf", &b);

  if (mode == 2) {
    a = a * M_PI / 180.0;
    b = b * M_PI / 180.0;
  }

  printf("Enter number of subintervals n (must be multiple of 6): ");
  scanf("%d", &n);

  if (n % 6 != 0) {
    printf("n must be a multiple of 6.\n");
    return 1;
  }

  double h = (b - a) / n;
  double *y = (double *)malloc((n + 1) * sizeof(double));
  if (!y) {
    printf("Memory allocation failed.\n");
    return 1;
  }
  for (int i = 0; i <= n; i++)
    y[i] = f(a + i * h);

  // (3h/10) per group of 6, coefficients: 1, 5, 1, 6, 1, 5, 1
  double result = 0;
  int groups = n / 6;
  for (int g = 0; g < groups; g++) {
    int s = g * 6;
    result += y[s] + 5 * y[s + 1] + y[s + 2] + 6 * y[s + 3] + y[s + 4] +
              5 * y[s + 5] + y[s + 6];
  }
  result *= 3.0 * h / 10.0;

  printf("\nResult = %f\n", result);

  free(y);
  return 0;
}
