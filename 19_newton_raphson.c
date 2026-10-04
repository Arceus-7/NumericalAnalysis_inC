#include <math.h>
#include <stdio.h>

double f(double x) { return exp(x) + log(1 + x) / log(3) - 2.2; }

double df(double x) { return exp(x) + 1.0 / ((1 + x) * log(3)); }

int main() {
  double x, x1, eps;
  int k, n = 0;

  printf("Enter initial guess: ");
  scanf("%lf", &x);
  printf("Enter decimal places of accuracy: ");
  scanf("%d", &k);

  eps = pow(10, -k);

  printf("\n n\t x\t\t f(x)\t\t f'(x)\n");

  do {
    double fx = f(x);
    double dfx = df(x);

    if (fabs(dfx) < 1e-12) {
      printf("Derivative too small, method fails.\n");
      return 1;
    }

    printf("%2d\t%.6f\t%.6f\t%.6f\n", n, x, fx, dfx);
    x1 = x - fx / dfx;
    if (fabs(x1 - x) < eps)
      break;
    x = x1;
    n++;
  } while (n < 100);

  printf("\nRoot = %.6f (correct to %d decimal places)\n", x1, k);

  return 0;
}
