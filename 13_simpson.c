#include <math.h>
#include <stdio.h>


double f(double x) { return sqrt(sin(x) + cos(x)); }

int main() {
  int n;
  double a, b;

  printf("Enter lower limit a: ");
  scanf("%lf", &a);
  printf("Enter upper limit b: ");
  scanf("%lf", &b);
  printf("Enter number of subintervals n (even for I_s): ");
  scanf("%d", &n);

  double h = (b - a) / n;
  double y[n + 1];
  for (int i = 0; i <= n; i++)
    y[i] = f(a + i * h);

  // I_t = (h/2)[y0 + 2(y1+y2+...+yn-1) + yn]
  double It = y[0] + y[n];
  for (int i = 1; i < n; i++)
    It += 2 * y[i];
  It *= h / 2;

  printf("\nI_t = %f\n", It);

  // I_s = (h/3)[y0 + 4(odd terms) + 2(even terms) + yn], n must be even
  if (n % 2 != 0) {
    printf("I_s needs even n, skipped.\n");
  } else {
    double Is = y[0] + y[n];
    for (int i = 1; i < n; i++) {
      if (i % 2 == 1)
        Is += 4 * y[i];
      else
        Is += 2 * y[i];
    }
    Is *= h / 3;
    printf("I_s = %f\n", Is);
  }

  return 0;
}
