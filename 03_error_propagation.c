#include <math.h>
#include <stdio.h>


int main() {
  double a, b, err_a, err_b;

  printf("Enter first number (a): ");
  scanf("%lf", &a);
  printf("Enter absolute error in a: ");
  scanf("%lf", &err_a);
  printf("Enter second number (b): ");
  scanf("%lf", &b);
  printf("Enter absolute error in b: ");
  scanf("%lf", &err_b);

  double sum = a + b;
  double err_sum = err_a + err_b;
  printf("\nSUM: a + b = %.6f\n", sum);
  printf("  Abs error = %.6f\n", err_sum);
  printf("  Rel error = %.6f\n", err_sum / fabs(sum));

  double diff = a - b;
  double err_diff = err_a + err_b;
  printf("\nDIFFERENCE: a - b = %.6f\n", diff);
  printf("  Abs error = %.6f\n", err_diff);
  printf("  Rel error = %.6f\n", err_diff / fabs(diff));
  if (fabs(diff) < fabs(a) * 0.01)
    printf("  WARNING: a and b are close, relative error is amplified!\n");

  double prod = a * b;
  double rel_err_prod = (err_a / fabs(a)) + (err_b / fabs(b));
  double err_prod = fabs(prod) * rel_err_prod;
  printf("\nPRODUCT: a * b = %.6f\n", prod);
  printf("  Rel error = %.6f\n", rel_err_prod);
  printf("  Abs error = %.6f\n", err_prod);

  if (fabs(b) > 1e-15) {
    double quot = a / b;
    double rel_err_quot = (err_a / fabs(a)) + (err_b / fabs(b));
    double err_quot = fabs(quot) * rel_err_quot;
    printf("\nQUOTIENT: a / b = %.6f\n", quot);
    printf("  Rel error = %.6f\n", rel_err_quot);
    printf("  Abs error = %.6f\n", err_quot);
  } else {
    printf("\nQUOTIENT: b is zero, division undefined.\n");
  }

  return 0;
}
