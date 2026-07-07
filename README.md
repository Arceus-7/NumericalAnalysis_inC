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

All programs are interactive. They will prompt you for input data points and the value to interpolate.
