/**************************************************************
 * This programme solves heat difussion equation using
 * explicit finite difference. Constant value boundary conditions
 * are assumed. This is to illustrate the numerical convergence
 * of this simplest explicit method, with varying time step.
 * 
 * Compile: gcc -Wall -g -std=c99 -o w6demo w6demo.c -lm
 * ************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(void) {
    /* Assign a value of pi */
    double pi = 4.0*atan(1.0);
    /* Array to store current and next time step values */
    double *T, *T_n;
    double length = 1.0;
    double deriv, x;
    /* Number of points on the spatial grid */
    long nx = 10;
    
    /* Need to include both boundary points at x_0 and x_N,
    so that domain is length 1.0 */
    double dx = length/(nx-1);
    double time_final = 1.0; 
    
    /* Time step set by stability limit dt/dx^2 < 0.5 */
    double dt = 0.5*(dx*dx);
    long nsteps = time_final/dt;
    
    /* In order to finish !exactly! at time_final, increase the
    number of steps by one and decrease the time step slightly;
    stability condition still satisfied. */
    nsteps += 1;
    dt = time_final/nsteps;

    /* Allocate memory for arrays. Exit if not enough memory. */
    T   = (double *)malloc(sizeof(double)*nx); 
    T_n = (double *)malloc(sizeof(double)*nx); 
    if( (T == NULL) || (T_n == NULL) ){
        printf("!!! Memory allocation failed !!! Exiting...\n");
        return(1);
    }
    
    /* Space and time grid indices, respectively */
    long k; long j;
    
    /* Initial condition: delta function at midpoint (init_pulse=1) 
    or sinusoidal peaking at midpoint (init_pulse=0). Both are
    consistent with the assumed boundary conditions
    T[0] = T[nx-1] = 0.*/
    int init_pulse = 0;
    if (init_pulse){
        for(k = 0; k < nx ;k++){
            T[k] = 0.0;
        }
        T[nx/2] = 1.0;
    }
    else{
        for(k = 0; k < nx; k++){
            x = k*dx;
            T[k] = sin(pi*x);
        }
    }
    /* Open the data file expected by w6demo_analyse.m. */
    FILE *data_fp = fopen("w6demo.dat", "w");
    if (data_fp == NULL) {
        perror("Could not open w6demo.dat");
        free(T);
        free(T_n);
        return(1);
    }

    /* Print first time step */
    double t0 = 0.0;
    for(k = 0; k < nx ; k++) {
        fprintf(data_fp, "%g %g %g\n", t0, k*dx, T[k]);
    }
    
    /* Write output parameters to a file to make it easier
    to read in and plot the simulation data. */
    FILE *fp = fopen("w6demo_params","w");
    if (fp == NULL) {
        perror("Could not open w6demo_params");
        fclose(data_fp);
        free(T);
        free(T_n);
        return(1);
    }
    fprintf(fp,"%ld %ld %g %g \n", nx, nsteps, dx, dt);
    fclose(fp);

    /* The numerical solution starts here */
    for(j = 0; j < nsteps; j++) {
        /* Loop over interior points, k in [1, nx-1].
        Boundary points always have T[0] = T[nx-1] = 0. */
        for(k = 1; k < (nx-1); k++) {
            deriv = (T[k-1] + T[k+1] - 2*T[k])/(dx*dx);
            T_n[k] = T[k] + deriv * dt;
        }
        T_n[0] = 0;
        T_n[nx-1] = 0;
        /* Copy temperature at next step back into current step */
        for(k = 0; k < nx; k++) {
            T[k] = T_n[k];
            fprintf(data_fp, "%g %g %g\n", (j + 1)*dt, k*dx, T[k]);
        }
    }
    
    /* Free allocated memory */
    fclose(data_fp);
    free(T);
    free(T_n);
    
    return 0;
}
