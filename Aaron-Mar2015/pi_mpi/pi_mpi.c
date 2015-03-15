#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "mpi.h"

int main (int argc, char* argv[])
{
    double x, y, r, pi;
    int i, count = 0, total_count;
    int niter, total_niter;
    int my_rank, process; // holds process's rank id

    MPI_Init(&argc, &argv);                   // start MPI
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);  // get rank
    MPI_Comm_size(MPI_COMM_WORLD, &process);
    niter = 1e8 / process;
    srand(time(NULL)*(my_rank+17887527)); // set random seed
    printf("Process: %i/%i\tTest random(): %g\n",
           my_rank, process, (double)rand() / RAND_MAX);

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

    /* collect count and niter totals */
    MPI_Reduce(&count, &total_count, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    MPI_Reduce(&niter, &total_niter, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    pi = 4.0 * ( (double)total_count / (double)total_niter );
    if ( !my_rank ) /* root */
        printf("Pi: %f\n", pi); // p = 4(m/n)

    MPI_Finalize();
    return 0;
}