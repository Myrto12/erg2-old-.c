#include <stdio.h>
#define I 10
#define J 20
void top_horiz_temp(double x[I][J]);
void left_vertical_temp(double x[I][J]);
void bottom_horiz_temp(double x[I][J]);
void right_vertical_temp(double x[I][J]);
void internal_temp(double x[I][J]);
void top_left_corner(double x[I][J]);
void top_right_corner(double x[I][J]);
void bottom_left_corner(double x[I][J]);
void bottom_right_corner(double x[I][J]);
void reset(void);
void time(void);
int print_temp(double x[I][J]);
double next_temp(double x[I][J]);

int main(void){
    double temp[I][J];
    time();
    top_horiz_temp(temp);
    left_vertical_temp(temp);
    bottom_horiz_temp(temp);
    right_vertical_temp(temp);
    internal_temp(temp);
    top_left_corner(temp);
    top_right_corner(temp);
    bottom_left_corner(temp);
    bottom_right_corner(temp);
    print_temp(temp);
    reset();
    next_temp(temp);
    getchar();
    return 0;
}

void top_horiz_temp(double x[I][J]) {
    int j;
    for (j=1; j<19; j++){
        x[0][j] = 2.00;
    }

}

void left_vertical_temp(double x[I][J]){
    int i;
    for (i=1; i<9; i++){
        x[i][0] = 4.00;
    }
}
void bottom_horiz_temp(double x[I][J]){
    int j;
    for (j=1; j<19; j++){
        x[9][j] = 3.00;
    }

}

void right_vertical_temp(double x[I][J]){
    int i;
    for (i=1; i<9; i++){
        x[i][19] = -5.00;
    }


}
void internal_temp(double x[I][J]){
    int i,j;
    for(i=1; i<9; i++){
        for (j=1; j<19; j++){
            x[i][j] = 1.00;
        }
    }
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

void top_left_corner(double x[I][J]){
    double temp1 = (x[0][1] + x[1][0]) /2;
    x[0][0] = temp1;
    
}

void top_right_corner(double x[I][J]){
    double temp2 = (x[0][18] + x[1][19]) /2;
    x[0][19] = temp2;
}

void bottom_left_corner(double x[I][J]){
    double temp3 = (x[8][0] + x[9][1]) /2;
    x[9][0] = temp3;
}

void bottom_right_corner(double x[I][J]){
    double temp4 = (x[9][18] + x[8][19]) /2;
    x[9][19] = temp4;
}

void reset(void){
    printf("reset\n");
}

void time(void){
    printf("time\n");
}

double next_temp(double x[I][J]){
    printf("next_temp");
}

