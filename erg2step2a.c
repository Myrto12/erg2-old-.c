#include <stdio.h>
#define N 10
int load(double x[N]) ;
int print(double x[N]) ;
double computesum(double x[N]);
void printsum(double sum);
int main( ) {
double data[N];
double sum;
load(data);
print(data);
sum = computesum(data);
printsum(sum);
getchar();
getchar();
return 0;
}
int print(double x[N]) {
int i;
for (i=0; i<N; i++) {
printf(" %g ", x[i]) ;
}
return 0;
}
int load(double x[N]) {
int i;
for (i=0; i<N; i++) {
x[i] = ((double) i) / N ;
}
return 0;
}
double computesum(double x[N]) {
    double sum = 0.0;
    int i;
    for (i=0; i<N; i++) {
        sum = sum + x[i];
    }
    return sum;
}
void printsum(double sum){
    printf("\nsum= %g ", sum);
}