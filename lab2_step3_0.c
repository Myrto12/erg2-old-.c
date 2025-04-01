#include <stdio.h>
#define I 10
#define J 20
#define top_temp 2.00
#define bottom_temp 3.00
#define left_temp 4.00
#define right_temp -5.00

void change_time(int time);
int print_temp(double x[I][J]);
double next_temp(double x[I][J]);
void reset(double x[I][J]);

int main(void){
    double temp[I][J];
    reset(temp);
    change_time(0);
    print_temp(temp);
    next_temp(temp);
    getchar();   // για  να μην σβήνει το terminal
    return 0;
}


int print_temp(double x[I][J]){
    int i,j;
    for (i=0; i<10; i++){
        for (j=0; j<20; j++){
            printf(" %.2f", x[i][j]);
        }
        printf("\n");
    }
}

void reset(double x[I][J]){
    int i,j;
    for (j=1; j<19; j++){         //εξωτερικες
        x[0][j] = top_temp;
    }
    for (i=1; i<9; i++){
        x[i][0] = left_temp;
    }
    for (j=1; j<19; j++){
        x[9][j] = bottom_temp;
    }
    for (i=1; i<9; i++){
        x[i][19] = right_temp;
    }

    for(i=1; i<9; i++){         //εσωτερικες
        for (j=1; j<19; j++){
            x[i][j] = 1.00;
        }
    }

    x[0][0] = (x[0][1] + x[1][0]) /2;          //γωνιες
    x[0][19] = (x[0][18] + x[1][19]) /2;
    x[9][0] = (x[8][0] + x[9][1]) /2;
    x[9][19] = (x[9][18] + x[8][19]) /2;
}
    

void change_time(int time){
    printf("time: %d\n", time);
}

double next_temp(double x[I][J]){
    printf("next_temp");
}

