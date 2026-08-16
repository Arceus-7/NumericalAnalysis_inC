// idk why tf we are doing this for numerical integration when midpoint rule
// exists
#include <math.h>
#include <stdio.h>

#define pi 3.14159265359
double a, b;
double f(double x) { return sqrt(sin(x) + cos(x)); }
// trapezoidal rule part which I dont think I need to fucking explain
double trap(int n) {
  double h = (b - a) / n, sum = f(a) + f(b);
  for (int i = 1; i < n; i++) {
    sum += 2 * f(a + i * h);
  }
  return (h / 2.0) * sum;
}
int main() {
  int d, n = 1;
  double eps, I1, I2, diff;
  printf("Enter lower limit: ");
  scanf("%lf", &a);
  printf("Enter upper limit: ");
  scanf("%lf", &b);
  a = a * pi / 180;
  b = b * pi / 180;
  printf("Enter accuracy: ");
  scanf("%d", &d);
  eps = pow(10, -(d + 1));
  I1 = trap(n);
  do {
    n++;
    I2 = trap(n);
    diff = fabs(I1 - I2);
    I1 = I2;
  } while (diff > eps && n < 50);
  printf("\nIntegral value: %f\n", I2);
  printf("Correct upto %d decimal places after %d subintervals\n", d, n);
  return 0;
}