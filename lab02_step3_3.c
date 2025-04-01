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
void compute_normalized_temp(double x[I][J], int normalized_temp[I][J]);
void print_normalized_temp(int y[I][J]);
void histogram(int x[I][J]);
double compute_diff(double x[I][J],double y[I][J]);
void stable_state(double x[I][J]);

int main(void){
    double temp[I][J];
    int normalized_temp[I][J];
    double copy_of_previous_temp[I][J];
    int time;
    int k;
    double total_diff = 0;
    printf("Chpose time : ");
    scanf(" %d", &time);
    reset(temp);
    for (k=0; k<(time+1); k++){
        change_time(k);
        print_temp(temp);
        printf("\n");
        compute_normalized_temp(temp,normalized_temp);
        print_normalized_temp(normalized_temp);
        histogram(normalized_temp);
        next_temp(temp);
    }
    reset(temp);
    stable_state(temp);
    print_temp(temp);

    getchar();
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
    int time = 1;
    double previous_temp[I][J];
    for (k=1; k<(time+1); k++){
        copy_array(x,previous_temp);
        compute_next_array(x, previous_temp);

    }
    return;
}



void compute_normalized_temp(double x[I][J], int normalized_temp[I][J]){
    double max = 4.00;
    double min = -5.00;
    double width = 9.00;
    double step = 0.90;
    double z[I][J];
    copy_array(x,z);
    int i,j,l;
    for(i=0; i<I; i++){
        for (j=0; j<J; j++){
            if (z[i][j] >= 0){
                z[i][j] = z[i][j] +5.50;
            }
            else{
                z[i][j] = z[i][j] +4.49;

            }

        }
    }
    for(i=0; i<I; i++){
        for (j=0; j<J; j++){
            normalized_temp[i][j] = z[i][j];
        }
    }


}

void print_normalized_temp(int y[I][J]){
    int i,j;
    for (i=0; i<10; i++){
        for (j=0; j<20; j++){
            printf(" %d", y[i][j]);
        }
        printf("\n");
    }

}

void histogram(int x[I][J]){
    int i,j,l,m;
    int counter = 0;
    for (l=0; l<10; l++){
        for (i=0; i<I; i++){
            for (j=0; j<J; j++){
                if (x[i][j] == l){
                    counter += 1;

                }
                
    
            }
        }
        printf("%d  ", l);
        for (m=0; m<counter; m++){
            printf("#");
        }
        printf("\n");
        counter = 0;
        
    }
}

double compute_diff(double x[I][J],double y[I][J]){
    int i,j;
    double diff;
    double total_diff;
    
    for (i=0; i<I; i++){
        for (j=0; j<J; j++){
            diff = y[i][j] - x[i][j];
            if (diff<0){
                diff = -diff;
            }
            total_diff += diff;
        }
        
    }
    return total_diff;
}
void stable_state(double x[I][J]){
    double copy_of_previous_temp[I][J];
    int time = 0;
    do{
        copy_array(copy_of_previous_temp, x);
        next_temp(x);
        compute_diff(x, copy_of_previous_temp);
        time +=1;
    }
    while (compute_diff(x, copy_of_previous_temp) > 1);
    printf("Stable state");
    change_time(time);
}





