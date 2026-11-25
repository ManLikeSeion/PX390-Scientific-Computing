/***********************************************************
 * This programme solves 1D advection equation using forward
 * time centered space (FTSC) method. Periodic boundary
 * conditions are used. This is to illustrate that the FTCS
 * approach is not stable.
 * 
 * Compile:
 * gcc -Wall -Werror -std=c99 -o w7wrkshop1 w7wrkshop1.c
 * Run:
 * ./w7wrkshop1 > advftcs.dat
 * *********************************************************/
#include <stdlib.h>
#include <stdio.h>

int main(void) {
  /* Current and next time step values */
  double *y, *y_next;
  double lslope;
  /* Final time */
  double time = 100.0;
  /* Time step */
  double ts =0.2;
  /* Note a large dx value */
  double dx = 1.0;		      
  /* Advection velocity */
  double vel = 1.0; 
  int nsteps = time/ts;
  /* Domain length */
  int len = 100;
  int i, j, jm, jp;

  /* Allocate the memory for spatial grid */
  y      = (double *) malloc(sizeof(double)*len); 
  y_next = (double *) malloc(sizeof(double)*len); 
  /* Validate the pointers */
  if( (y==NULL) || (y_next==NULL)){
    printf("\n!!! MEMORY ALLOCATION FAILED !!! Exiting...\n");
    return(1);
  }

  /* Initial condition is a "top hat" profile */
  for(j=0; j < len; j++) {
    if((dx*j > len*0.25) && (dx*j < len*0.5)){
      y[j] = 1.0;
    } else {
      y[j] = 0.0;
    }
  }

  /* Write output parameters to a file to make it easier
     to read in and plot the simulation data             */
  FILE *fp = fopen("advparams","w");
  fprintf(fp,"%d %d %g %g \n", len, nsteps, dx, ts);
  fclose(fp);

  /* Loop over timesteps */
  for(i=0; i<nsteps; i++) {
    for (j=0; j<len; j++ ) {
      printf("%g %g \n",j*dx,y[j]);
    }
    /* Loop over points */
    for (j=0; j<len; j++) {
      /* Centred space indices for the periodic boundary */
      jm = (j + len-1)%len;
      jp = (j + 1)% len;
      /* Finite difference evaulation of the gradient */
      lslope = (y[jp] - y[jm]) / ( 2 * dx );
      /* Forward time step */
      y_next[j] = y[j] - lslope * ts * vel;
    }
    /* Copy the next time step solution to the current one */
    for (j=0; j<len; j++) {
      y[j] = y_next[j];
    }
  }

  return(0);
}
