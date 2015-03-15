#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main (int argc, char* argv[])
{
    double x, y, r, pi;
    int i, count = 0, niter = 1e8;
    srand(time(NULL)); /* set random seed */

    /* main loop */
    for ( i = 0; i < niter; ++i )
    {
        /* get random points */
        x = (double)rand() / RAND_MAX;
        y = (double)rand() / RAND_MAX;
        r = sqrt(x*x + y*y);

        /* check to see if point is in unit circle */
        if ( r <= 1 ) ++count;
    } /* end main loop */

    pi = 4.0 * ( (double)count / (double)niter );
    printf("Pi: %f\n", pi);  // p = 4(m/n)
    return 0;
}