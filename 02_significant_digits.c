#include <math.h>
#include <stdio.h>


int main() {
  double true_val, approx_val;

  printf("Enter true value: ");
  scanf("%lf", &true_val);
  printf("Enter approximate value: ");
  scanf("%lf", &approx_val);

  double error = fabs(true_val - approx_val);

  // x has m significant digits if |error| < 0.5 * 10^(log10(|x|) - m + 1)
  int sig_digits = 0;
  for (int m = 1; m <= 15; m++) {
    if (error < 0.5 * pow(10, floor(log10(fabs(true_val))) - m + 1))
      sig_digits = m;
    else
      break;
  }
  printf("Number of significant digits: %d\n", sig_digits);

  printf("\nCatastrophic cancellation demo:\n");
  printf("Solving x^2 - 1e8*x + 1 = 0\n\n");

  double a = 1.0, b = -1e8, c = 1.0;
  double disc = sqrt(b * b - 4 * a * c);

  double x1_unstable = (-b - disc) / (2 * a);
  double x2_unstable = (-b + disc) / (2 * a);

  printf("Standard quadratic formula:\n");
  printf("  x1 = %.15f\n", x1_unstable);
  printf("  x2 = %.15e  (lost significance)\n", x2_unstable);

  // avoid cancellation by using x2 = c/(a*x1) instead
  double x1_stable = (-b + disc) / (2 * a);
  double x2_stable = c / (a * x1_stable);

  printf("\nStabilized via x2 = c/(a*x1):\n");
  printf("  x1 = %.15f\n", x1_stable);
  printf("  x2 = %.15e\n", x2_stable);

  return 0;
}
