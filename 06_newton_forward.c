#include <stdio.h>

#define MAX 20

int main() {
  int n;
  double x[MAX], y[MAX], diff[MAX][MAX];

  printf("Enter number of data points: ");
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    printf("x[%d], y[%d]: ", i, i);
    scanf("%lf %lf", &x[i], &y[i]);
  }

  double h = x[1] - x[0];

  for (int i = 0; i < n; i++)
    diff[i][0] = y[i];

  for (int j = 1; j < n; j++)
    for (int i = 0; i < n - j; i++)
      diff[i][j] = diff[i + 1][j - 1] - diff[i][j - 1];

  double xp;
  printf("\nEnter x to interpolate: ");
  scanf("%lf", &xp);

  double u = (xp - x[0]) / h;
  double result = diff[0][0];
  double u_term = 1.0;

  // u_term accumulates u(u-1)(u-2)...(u-i+1) / i!
  for (int i = 1; i < n; i++) {
    u_term *= (u - (i - 1)) / i;
    result += u_term * diff[0][i];
  }

  printf("\nh = %.4f, u = %.4f\n", h, u);
  printf("Interpolated value at x = %.4f is y = %.6f\n", xp, result);

  return 0;
}
