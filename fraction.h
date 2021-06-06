#ifndef FRACTION_H_
#define FRACTION_H_
typedef struct{
    unsigned long long int precision;
    char *fraction;
}fraction;

void initmult(fraction x);
void freemult();
void initF(fraction* f , unsigned long long int p , char* number);
void freeF(fraction* f);
void mult(fraction x, unsigned long long int j, fraction* result);
void printF(fraction f);
void addF(fraction x, fraction y, fraction* result);
int compF(fraction x, fraction y);
#endif