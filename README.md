# Numerical Analysis in C

C implementations of numerical methods covered in Numerical Analysis.

## Disclaimer

This repository is created for my personal use and coursework. The implementations are meant for me to keep a tab of the things being done in class and for future reference. If you choose to use any of this code, you do so entirely at your own risk, because I am a fucking retard so dont trust my code. Thank you

## Contents

### Unit I: Errors in Numerical Computations

| File | Description |
|------|-------------|
| `01_errors.c` | Absolute, relative, percentage, and round-off error |
| `02_significant_digits.c` | Significant digits and numerical instability |
| `03_error_propagation.c` | Error in sum, difference, product, and quotient |
| `04_finite_differences.c` | Forward, backward, central, and shift operators |

### Unit II: Interpolation

| File | Description |
|------|-------------|
| `05_difference_table.c` | Forward and backward difference tables |
| `06_newton_forward.c` | Newton's forward interpolation |
| `07_newton_backward.c` | Newton's backward interpolation |
| `08_lagrange.c` | Lagrange interpolation |
| `09_newton_divided_diff.c` | Newton's divided difference interpolation |
| `10_inverse_interpolation.c` | Inverse interpolation using Lagrange |
| `11_hermite.c` | Hermite interpolation |

### Unit III: Numerical Integration

| File | Description |
|------|-------------|
| `12_numerical_integration.c` | Basic numerical integration |
| `13_simpson.c` | Trapezoidal and Simpson's 1/3 rule |
| `14_weddle.c` | Weddle's rule |
| `15_trapezoidalrule.c` | Trapezoidal rule with accuracy control |

### Unit IV: Root Finding & Linear Systems

| File | Description |
|------|-------------|
| `16_tabulation.c` | Tabulation method for root finding |
| `17_bisection.c` | Bisection method |
| `18_regula_falsi.c` | Regula Falsi (False Position) method |
| `19_newton_raphson.c` | Newton-Raphson method |
| `20_lu_decomposition.c` | LU Decomposition (Doolittle's method) |
| `21_gauss_jordan.c` | Gauss-Jordan elimination |
| `22_gauss_jacobi.c` | Gauss-Jacobi method |
| `23_gauss_seidel.c` | Gauss-Seidel method |

## How to compile and run

You need a C compiler (GCC, Clang, or MSVC). Each file is a standalone program.

To compile a single file:

```
gcc -o 06_newton_forward 06_newton_forward.c -lm
```

To run it:

```
./06_newton_forward
```

On Windows without a Unix-like shell:

```
06_newton_forward.exe
```

To compile everything at once (PowerShell):

```powershell
Get-ChildItem *.c | ForEach-Object { gcc -o ($_.BaseName + ".exe") $_.FullName -lm }
```

To compile everything at once (Bash):

```bash
for f in *.c; do gcc -o "${f%.c}" "$f" -lm; done
```

All programs are interactive and will prompt you for input.
