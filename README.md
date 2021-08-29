# curly-fiesta
### or how to do a **_basic_ printf** in C

>'cspdiuxX%' flag printf recoded

## SYNOPSIS
```c
#include <stdio.h>

int ft_printf(const char *format, ...);
```

## DESCRIPTION
The function printf(), from the **printf()** family, produces output to _stdout_ according to a _format_ as described below.

### Format of the format string
```
%[$][flags][width][.precision][length modifier]conversion
```

## Flags

| flag | Description                                    |   |   |   |   |   |   |   |   |   |   |   |   |   |
| :--: | :--------------------------------------------: | - | - | - | - | - | - | - | - | - | - | - | - | - |
| flag | Description                                    | c | s | d | i | u | x | X | p | % | n | f | e | g |


| flag | Description                                    | c | s | d | i | u | x | X | p | % | n | f | e | g |
| :--: | ---------------------------------------------: | - | - | - | - | - | - | - | - | - | - | - | - | - |
| `#`  | "0x" or "0X" prepended                         |   |   |   |   |   | x | x |   |   |   |   |   |   |
|      | always decimal point, even if no digit follows |   |   |   |   |   |   |   |   |   |   | x | x | x |
| `0`  |                                                |   |   |   |   |   | x | x |   |   |   |   |   |   |
| `-`  |                                                |   |   |   |   |   | x | x |   |   |   |   |   |   |
| ` `  |                                                |   |   |   |   |   | x | x |   |   |   |   |   |   |
| `+`  |                                                |   |   |   |   |   | x | x |   |   |   |   |   |   |

## Width



## Precision

## Length Modifier

## Conversions
### Flag characters
The character % is followed by zero or more of the following
       flags:

       #      The value should be converted to an "alternate form".  For
              o conversions, the first character of the output string is
              made zero (by prefixing a 0 if it was not zero already).
              For x and X conversions, a nonzero result has the string
              "0x" (or "0X" for X conversions) prepended to it.  For a,
              A, e, E, f, F, g, and G conversions, the result will
              always contain a decimal point, even if no digits follow
              it (normally, a decimal point appears in the results of
              those conversions only if a digit follows).  For g and G
              conversions, trailing zeros are not removed from the
              result as they would otherwise be.  For other conversions,
              the result is undefined.

       0      The value should be zero padded.  For d, i, o, u, x, X, a,
              A, e, E, f, F, g, and G conversions, the converted value
              is padded on the left with zeros rather than blanks.  If
              the 0 and - flags both appear, the 0 flag is ignored.  If
              a precision is given with a numeric conversion (d, i, o,
              u, x, and X), the 0 flag is ignored.  For other
              conversions, the behavior is undefined.

       -      The converted value is to be left adjusted on the field
              boundary.  (The default is right justification.)  The
              converted value is padded on the right with blanks, rather
              than on the left with blanks or zeros.  A - overrides a 0
              if both are given.

       ' '    (a space) A blank should be left before a positive number
              (or empty string) produced by a signed conversion.

       +      A sign (+ or -) should always be placed before a number
              produced by a signed conversion.  By default, a sign is
              used only for negative numbers.  A + overrides a space if
              both are used.

- [x] Basic printf conversions - cspdiuxX%
- [ ] Bonus #1 - '-0.' and min field width, minus, zero, precision
- [ ] Bonus #2 - '# +' pound, space, plus

- [ ] Add flag details
- [ ] ft_printf --> ft_pf
- [ ] 
