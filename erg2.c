#include <stdio.h>
#define N 10
int main( ) {
int i;
double data[N];
double sum = 0.0;
for (i=0; i<N; i++) {
data[i] = ((double) i) / N ;
}
for (i=0; i<N; i++) {
printf(" %g ", data[i]);
sum = sum + data[i];
}
/* add here your code to
compute sum of array elements */
printf("\n%g\n", sum);
return 0;
}