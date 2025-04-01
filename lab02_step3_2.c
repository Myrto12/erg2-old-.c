#include <stdio.h>
#define I 10
#define J 20
#define top_temp 2.00
#define bottom_temp 3.00
#define left_temp 4.00
#define right_temp -5.00

void change_time(int time);
int print_temp(double x[I][J]);
void next_temp(double x[I][J]);
void reset(double x[I][J]);
void copy_array(double x[I][J], double previous_temp[I][J]);
void compute_next_array(double x[I][J], double previous_temp[I][J]);
void find_max(double x[I][J]);
void find_min(double x[I][J]);
void normalization(double x[I][J]);
int main(void){
    double temp[I][J];
    int time = 2;
    int k;
    reset(temp);
    change_time(0);
    print_temp(temp);
    next_temp(temp);
    getchar();
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

void copy_array(double x[I][J], double previous_temp[I][J]){
    int i,j;
        for (i=0; i<I; i++){
            for (j=0; j<J; j++){
                previous_temp[i][j] = x[i][j];
            }
        }

}

void compute_next_array(double x[I][J], double previous_temp[I][J]){
    int i,j,k;
    for (i=1; i<(I-1); i++){
        for (j=1; j<(J-1); j++){
            x[i][j] = 0.1 * (previous_temp[i-1][j-1] + previous_temp[i-1][j] + previous_temp[i-1][j+1] + previous_temp[i][j-1] + 2*previous_temp[i][j]
            + previous_temp[i][j+1] + previous_temp[i+1][j-1] + previous_temp[i+1][j] + previous_temp[i+1][j+1]);
        }
    }
    for (i=(I-2); i>k; i--){
        for (j=(J-2); j>k; j--){
            x[i][j] = 0.1 * (previous_temp[i-1][j-1] + previous_temp[i-1][j] + previous_temp[i-1][j+1] + previous_temp[i][j-1] + 2*previous_temp[i][j]
            + previous_temp[i][j+1] + previous_temp[i+1][j-1] + previous_temp[i+1][j] + previous_temp[i+1][j+1]);
        }
    }

}

void next_temp(double x[I][J]){
    int i,j,k;
    int time = 2;
    double previous_temp[I][J];
    for (k=1; k<(time+1); k++){
        copy_array(x,previous_temp);
        compute_next_array(x, previous_temp);
        change_time(k);
        print_temp(x);
        find_max(x);
        find_min(x);


    }
    return;
}

void find_max(double x[I][J]){
    int i,j;
    double max = x[0][0];
    for (i=0; i<I; i++){
        for (j=0; j<J; j++){
            if (x[i][j] > max){
                max = x[i][j]; 
            }
        }
    }
    printf("max : %.2f\n", max);
}

void find_min(double x[I][J]){
    int i,j;
    double min = x[0][0];
    for (i=0; i<I; i++){
        for (j=0; j<J; j++){
            if (x[i][j] <min){
                min = x[i][j]; 
            }
        }
    }
    printf("min : %.2f\n", min);
}

void normalization(double x[I][J]);
