#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <omp.h>

int main (int argc, char* argv[])
{
    double x, y, r, pi;
    int i, count = 0, niter = 1e8;

  #pragma omp parallel
  {
    srandom(time(NULL)*(omp_get_thread_num()+17887527));  // random seed
    printf("Process: %i/%i\tTest random(): %g\n",
           omp_get_thread_num(),
           omp_get_num_threads(),
           (double)random() / RAND_MAX);

    #pragma omp for private(x, y, r, i) reduction(+:count)
    for ( i = 0; i < niter; ++i )
    {
        /* get random points */
        x = (double)random() / RAND_MAX;
        y = (double)random() / RAND_MAX;
        r = sqrt(x*x + y*y);

        /* check to see if point is in unit circle */
        if ( r <= 1 ) count++;
    } /* end main loop */
  }

    pi = 4.0 * ( (double)count / (double)niter );
    printf("Pi: %f\n", pi);  // p = 4(m/n)
    return 0;
}
