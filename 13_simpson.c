#include <math.h>
#include <stdio.h>

#define M_PI 3.14159265358979323846

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

  printf("Enter number of subintervals n (even for I_s): ");
  scanf("%d", &n);

  double h = (b - a) / n;

  // I_t = (h/2)[y0 + 2(y1+y2+...+yn-1) + yn]
  double It = f(a) + f(b);
  for (int i = 1; i < n; i++) {
    It += 2 * f(a + i * h);
  }
  It *= h / 2;

  printf("\nI_t = %f\n", It);

  // I_s = (h/3)[y0 + 4(odd terms) + 2(even terms) + yn], n must be even
  // voodoo fucking shit man
  if (n % 2 != 0) {
    printf("I_s needs even n, skipped.\n");
  } else {
    double Is = f(a) + f(b);
    for (int i = 1; i < n; i++) {
      if (i % 2 == 1)
        Is += 4 * f(a + i * h);
      else
        Is += 2 * f(a + i * h);
    }
    Is *= h / 3;
    printf("I_s = %f\n", Is);
  }

  return 0;
}
