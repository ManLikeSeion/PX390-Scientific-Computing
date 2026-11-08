// m*dv/dt = F = -m*g - gamma*v

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define g   9.80665
#define MAX_TIME    10

void read_input(double*, double*, double*, double*, double*, double*);

int main(void){
    double dt, gamma;
    double x0, y0, vx0, vy0;
    double vx_c, vy_c, vx_n, vy_n;
    double *x, *y; //stores in the array, hence memory must be allocated
    long int nsteps, i;
    read_input(&x0, &y0, &vx0, &vy0, &gamma, &dt); //reads in from file
    nsteps = MAX_TIME / dt;

    x = malloc(sizeof(double) * nsteps);
    y = malloc(sizeof(double) * nsteps);

    if((x == NULL) || (y == NULL)){
        printf("\n!!! Memory allocation failed, exiting.");
        return 1;
    }
    
    x[0] = x0;y[0] = y0;
    vx_c = vx0;vy_c = vy0;
    vx_n = vy_n = 0;

    printf("Initial conditions: %lf %lf %lf\n", 0.0, x[0], y[0]);

    for(i = 0; i<nsteps; i++){
        vx_n = vx_c - gamma*vx_c*dt;
        vy_n = vy_c - gamma*vy_c*dt - g*dt;
        x[i+1] = vx_c*dt + x[i];
        y[i+1] = vy_c*dt + y[i];

        vx_c = vx_n; vy_c = vy_n;
        printf("%lf, %lf, %lf\n", (i+1)*dt, x[i+1], y[i+1]);
    }

    free(x); free(y);
    return 0;
}

void read_input(double *x0, double *y0, double *vx0, double *vy0, double *gamma, double *dt){
    FILE *infile;
    if(!(infile=fopen("C:/Users/seion/Documents/PX390/TestProject/src/w4demo0_input.txt","r"))){
        printf("Error opening file\n");
        exit(1);
    }

    if(6!=fscanf(infile, "%lf %lf %lf %lf %lf %lf", x0, y0, vx0, vy0, gamma, dt)){
        printf("Error reading parameters\n");
        exit(1);
    }
    fclose(infile);
}