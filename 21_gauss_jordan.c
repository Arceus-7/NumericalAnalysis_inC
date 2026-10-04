#include <math.h>
#include <stdio.h>

#define MAX 10

int main() {
  int n;
  double a[MAX][MAX + 1];

  printf("Enter number of equations: ");
  scanf("%d", &n);

  printf("Enter augmented matrix [A|b] row by row:\n");
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= n; j++)
      scanf("%lf", &a[i][j]);

  // Gauss-Jordan elimination
  for (int i = 0; i < n; i++) {
    // partial pivoting
    int max_row = i;
    for (int k = i + 1; k < n; k++) {
      if (fabs(a[k][i]) > fabs(a[max_row][i]))
        max_row = k;
    }
    for (int j = 0; j <= n; j++) {
      double temp = a[i][j];
      a[i][j] = a[max_row][j];
      a[max_row][j] = temp;
    }

    // make pivot = 1
    double pivot = a[i][i];
    if (fabs(pivot) < 1e-12) {
      printf("No unique solution exists.\n");
      return 1;
    }
    for (int j = 0; j <= n; j++)
      a[i][j] /= pivot;

    // eliminate column in all other rows
    for (int k = 0; k < n; k++) {
      if (k != i) {
        double factor = a[k][i];
        for (int j = 0; j <= n; j++)
          a[k][j] -= factor * a[i][j];
      }
    }
  }

  printf("\nSolution:\n");
  for (int i = 0; i < n; i++)
    printf("x[%d] = %.6f\n", i, a[i][n]);

  return 0;
}
