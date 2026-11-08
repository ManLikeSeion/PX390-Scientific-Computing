#include<math.h>

void efield(double *posx, double *posy, double *posz, double *Q, long ncharges, double x, double y, double z, double *ex, double *ey, double *ez){
    long int i;
    double dx, dy, dz, r2, r3, factor;
    *ex = 0.0;
    *ey = 0.0;
    *ez = 0.0; //initialise pointers

    for(i = 0; i < ncharges; i++){ //we need to do a sum so use a for loop over the arrays

        //E^j = \sum_i \frac{Q_i(r_i^j - \p_i^j}{|r_i^j -p_i^j|^3} so lets simplify this into components, and smaller parts at that
        // call the numerator dx^j = r^j - p^j
        dx = x - posx[i];
        dy = y - posy[i];
        dz = z - posz[i];
        r2 = dx*dx + dy*dy + dz*dz;
        r3 = r2 * sqrt(r2);
        factor = Q[i]/r3;
        *ex += factor*dx;
        *ey += factor*dy;
        *ez += factor*dz;
    }
}