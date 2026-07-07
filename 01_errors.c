#include <math.h>
#include <stdio.h>


int main() {
  double true_val, approx_val;

  printf("Enter true value: ");
  scanf("%lf", &true_val);
  printf("Enter approximate value: ");
  scanf("%lf", &approx_val);

  double abs_err = fabs(true_val - approx_val);
  double rel_err = abs_err / fabs(true_val);
  double pct_err = rel_err * 100.0;

  printf("\nAbsolute Error    = %.10f\n", abs_err);
  printf("Relative Error    = %.10f\n", rel_err);
  printf("Percentage Error  = %.10f%%\n", pct_err);

  printf("\nRound-off error demo:\n");

  float f_third = 1.0f / 3.0f;
  double d_third = 1.0 / 3.0;

  printf("1/3 in float   = %.20f\n", f_third);
  printf("1/3 in double  = %.20lf\n", d_third);
  printf("Round-off (float vs double) = %.20e\n",
         fabs(d_third - (double)f_third));

  // summing 0.1 ten times should give 1.0, but float can't represent 0.1
  float sum = 0.0f;
  for (int i = 0; i < 10; i++)
    sum += 0.1f;
  printf("\nSumming 0.1 ten times: expected 1.0, got %.20f\n", sum);
  printf("Accumulated round-off = %.20e\n", fabs(1.0 - (double)sum));

  return 0;
}
