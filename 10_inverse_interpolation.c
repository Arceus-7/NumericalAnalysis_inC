#include <stdio.h>

#define MAX 20

int main() {
  int n;
  double x[MAX], y[MAX];

  printf("Enter number of data points: ");
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    printf("x[%d], y[%d]: ", i, i);
    scanf("%lf %lf", &x[i], &y[i]);
  }

  double yp;
  printf("\nEnter y value to find corresponding x: ");
  scanf("%lf", &yp);

  // Lagrange interpolation with x and y swapped: treat y as independent
  // variable
  double result = 0.0;

  for (int i = 0; i < n; i++) {
    double Li = 1.0;
    for (int j = 0; j < n; j++) {
      if (j != i)
        Li *= (yp - y[j]) / (y[i] - y[j]);
    }
    result += Li * x[i];
  }

  printf("\nFor y = %.6f, the interpolated x = %.6f\n", yp, result);

  return 0;
}
