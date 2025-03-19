#include <stdio.h>
#define N 10
#define M 5
int main( ) {
int i;
int j;
double data[N][M];
double sum = 0.0;
for (i=0; i<N; i++) {
    for (j=0; j<M; j++) {
        data[i][j] = ((double) i*j)/N;
        printf(" %g ", data[i][j]);
    }
    printf("\n");
    
}
for (i=0; i<N; i++) {
    for (j=0; j<M; j++) {
        sum = sum + data[i][j];
    }

}
/* add here your code to
compute sum of array elements */
printf("\n%g\n", sum);
getchar();
return 0;
}