FracMult
==================
With this method we can compute values of any term with arbitrary-precision of a special sequence using a computer, where the values of the terms of the sequence are real numbers between 0 and 1. This sequence is <img src="https://latex.codecogs.com/svg.latex?\left(\{a_n\}\right)_{n=1}^{\infty}" title=" \left(\{\alpha\cdot n\}\right)_{n=1}^{\infty}" />, where {x} is the fractional part of real number x.

For example:
------------------------------------
We multiply the fractional part of real number x by arbitrary-precision with a positive integer N. 
```C
#include <stdio.h>
#include "fraction.h"
int  main()
{
    unsigned long long int N = 123456*1024*1024LL;
    unsigned long long int prec=28LL;
    fraction X,Y;
    initF(&X,prec,"1271828182845904523536028747");  // X = 0.1271828182845904523536028747
    printf("  X = ");
    printF(X);
    putchar('\n');
    initF(&Y,prec,"");
    initmult(X);
    
    mult(X,N,&Y);
    printf("result = ");
    printF(Y);
    putchar('\n');

    freemult();
    freeF(&X);
    freeF(&Y);
    return 0;
}
```
