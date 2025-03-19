#include <stdio.h>
#define N 10
#define M 3
int load(double x[N][M]) ;
int print(double x[N][M]) ;
double computesum(double x[N][M]);
void printsum(double sum);
void copy_array(double x[N][M], double newdata[N][M]);
int main( ) {
    double data[N][M];
    double sum;
    double newdata[N][M];
    load(data);
    print(data);
    sum = computesum(data);
    printsum(sum);
    copy_array(data, newdata);
    print(newdata);
    getchar();
    getchar();
    return 0;
}
int print(double x[N][M]) {
int i,j;
for (i=0; i<N; i++) {
    for (j=0; j<M; j++){
        printf(" %g ", x[i][j]) ;

    }
    printf("\n");
}
return 0;
}
int load(double x[N][M]) {
    int i,j;
    for (i=0; i<N; i++) {
        for (j=0; j<M; j++){
            x[i][j] = ((double) i*j) / N ;
        }
    }
    return 0;
}
double computesum(double x[N][M]) {
    double sum = 0.0;
    int i,j;
    for (i=0; i<N; i++) {
        for (j=0; j<M; j++){
            sum = sum + x[i][j];
        }
    }
    return sum;
}
void printsum(double sum) {
    printf("\nsum= %g\n", sum);
}
void copy_array(double x[N][M], double newdata[N][M]){
    int i,j;
    for (i=0; i<N; i++){
        for (j=0; j<M; j++){
            newdata[i][j] = x[i][j];
        }
    }
}
/*int copy_array(double x[N][M], double y[N][M]) {
    int i,j;
    for (i=0; i<N; i++) {
        for (j=0; j<M; j++){
            printf("%lf", x[i][j]);
        }
        printf("\n");
    }
    return 0;
}*/