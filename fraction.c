#include "fraction.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

fraction val[64];

void initmult(fraction x)
{
    int i;
    initF(&val[0],x.precision,x.fraction);
    for(i=1;i<64;i++)
        initF(&val[i],x.precision,"");

    for(i=1;i<64;i++)
   {
       addF(val[i-1],val[i-1],&val[i]);
    }
}

void freemult()
{
   for(int i=0;i<64;i++)
        freeF(&val[i]);
}

void mult(fraction x, unsigned long long int j, fraction* result)
{
   //initmult(x);
   unsigned long long int k=1;
   int i=0;
   fraction r1,r2;
   initF(&r1,x.precision,"");
   initF(&r2,x.precision,x.fraction);
      
    for(;i<64;i++)
    {
        if( (j & (k << i) ) !=0 )
            {
                addF(r1,val[i],&r2);
                memcpy(r1.fraction, r2.fraction, strlen(r2.fraction)+1);
            }
    }
    
    result->precision=r1.precision;
    memcpy(result->fraction, r2.fraction, strlen(r2.fraction)+1);
    freeF(&r1);
    freeF(&r2);
   // freemult();
}


void printF(fraction f)
{
    printf("0.%s",f.fraction);
}

void initF(fraction* f , unsigned long long int p , char* number)
{
    
    f->precision=p;
    
    f->fraction=malloc((p+1)*sizeof(char));
    if (f->fraction == NULL) {
        fprintf(stderr, "Unable to allocate enough memory for array!\n");
        
    }
    memset(f->fraction, '0', p*sizeof(char));
    if( strlen(number) > p ) strncpy(f->fraction, number, p);
    else strcpy(f->fraction,number);
       

    if(strlen(number)<p) if(f->fraction[strlen(number)]=='\0')f->fraction[strlen(number)]='0';
        f->fraction[p] = '\0';
}

void freeF(fraction* f)
{
    free(f->fraction);
}

void addF(fraction x, fraction y, fraction* result)
{
    unsigned long long int i;
    char d;
    int carry=0; 
    for (i = result->precision-1; i >= 0 ; i--)
    {
        d=x.fraction[i]+y.fraction[i]-48+carry;
        if(d>57) carry=1; else carry=0;
        if(carry==1) d=48+((d-48)%10);
        result->fraction[i]=d;
        if(i==0) break;
    }
}

// 1 - x>y, 2 - x<y, 0 - x==y
int compF(fraction x, fraction y)
{
    unsigned long long int i=0;
    for (; i < x.precision; i++)
    {
        if(x.fraction[i]!=y.fraction[i])
        {
            if(x.fraction[i]>y.fraction[i])
                return 1;
            else
                return -1;
        }
    }
    return 0;
}