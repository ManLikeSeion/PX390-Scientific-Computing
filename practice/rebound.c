#include<math.h>
#include<stdlib.h>
#include<stdio.h>

const double pi = 3.14159265358979323846;
const double G = 6.6743e-11;
const double AU = 1.496e11;
const double pc = 3.086e+16;

int stepper(double m1, double a, double dt, double t, double **x_out, double **y_out);

int main(void){

    // THESE CAN BE CHANGED
    //=============================
    double mass1 = 1.9884e30; //sun
    double semi_major_axis = 1*AU;
    double timestep_seconds = 20;
    double duration_seconds = 365*24*60*60;
    //=============================
    double *x_array = NULL;
    double *y_array = NULL;
    if (stepper(mass1, semi_major_axis, timestep_seconds, duration_seconds, &x_array, &y_array) != EXIT_SUCCESS){
        return EXIT_FAILURE;
    }
    
    //Write to file for matlab displaying
    FILE *file = fopen("practice/output.txt", "w");
    if(file == NULL) {
    perror("Could not open file");
    free(x_array);
    free(y_array);
    return EXIT_FAILURE;
    }
    fprintf(file, "x, y\n");
    long j;
    for(j=0; j<(duration_seconds/timestep_seconds); j++){
        fprintf(file, "%lf, %lf\n", x_array[j], y_array[j]);

    }
    fclose(file);
    free(x_array);
    free(y_array);
    return 0;
}

int stepper(double m1, double a, double dt, double t, double **x_out, double **y_out){
    long i;
    double theta_0=0;
    double theta_1, x_1, y_1;
    double x_0 = a;
    double y_0 = 0;
    double v = sqrt(G * m1 / a);

    double *x;
    double *y;
    double *theta;
    double steps = t/dt;

    theta = malloc(sizeof(double)*steps);
    x = malloc(sizeof(double)*steps);
    y = malloc(sizeof(double)*steps);
    if(x == NULL || y == NULL || theta == NULL){
        fprintf(stderr, "Memory allocation failed.\n");
        free(x);
        free(y);
        free(theta);
        return EXIT_FAILURE;
    }

    for(i = 0; i<steps; i++){
        x[i] = x_0;
        y[i] = y_0;
        theta[i] = theta_0;

        theta_1 = theta_0 + (v*dt)/a;
        x_1 = x_0 + v*sin(theta_1)*dt;
        y_1 = y_0 + v*cos(theta_1)*dt;

        theta_0 = theta_1;
        x_0 = x_1;
        y_0 = y_1;
    }
    *x_out = x;
    *y_out = y;
    free(theta);
    return EXIT_SUCCESS;
}