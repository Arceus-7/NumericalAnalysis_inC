#include <stdio.h>

#define MAX 20

int main() {
  int n;
  double x[MAX], f[MAX], fp[MAX];

  printf("Enter number of data points: ");
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    printf("x[%d]: ", i);
    scanf("%lf", &x[i]);
    printf("f(x[%d]): ", i);
    scanf("%lf", &f[i]);
    printf("f'(x[%d]): ", i);
    scanf("%lf", &fp[i]);
  }

  int m = 2 * n;
  double z[2 * MAX], Q[2 * MAX][2 * MAX];

  // each node x_i appears twice in z[], so z = {x0, x0, x1, x1, ...}
  // for repeated nodes, the first divided difference is set to f'(x_i)
  for (int i = 0; i < n; i++) {
    z[2 * i] = x[i];
    z[2 * i + 1] = x[i];
    Q[2 * i][0] = f[i];
    Q[2 * i + 1][0] = f[i];
    Q[2 * i + 1][1] = fp[i];
    if (i > 0)
      Q[2 * i][1] = (Q[2 * i][0] - Q[2 * i - 1][0]) / (z[2 * i] - z[2 * i - 1]);
  }

  // fill remaining divided differences normally
  for (int j = 2; j < m; j++) {
    for (int i = j; i < m; i++) {
      Q[i][j] = (Q[i][j - 1] - Q[i - 1][j - 1]) / (z[i] - z[i - j]);
    }
  }

  printf("\nDivided Difference Table:\n\n");
  printf("%-6s%-10s", "i", "z_i");
  for (int j = 0; j < m; j++) {
    printf("Q[i][%-2d]    ", j);
  }
  printf("\n");

  for (int i = 0; i < m; i++) {
    printf("%-6d%-10.4f", i, z[i]);
    for (int j = 0; j <= i && j < m; j++) {
      printf("%-12.6f", Q[i][j]);
    }
    printf("\n");
  }

  double xp;
  printf("\nEnter x to interpolate: ");
  scanf("%lf", &xp);

  // evaluate using the diagonal Q[i][i] as coefficients
  double result = Q[0][0];
  double product = 1.0;

  for (int i = 1; i < m; i++) {
    product *= (xp - z[i - 1]);
    result += Q[i][i] * product;
  }

  printf("\nInterpolated value at x = %.4f is y = %.6f\n", xp, result);

  return 0;
}
