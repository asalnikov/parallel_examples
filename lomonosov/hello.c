#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <mpi.h>

#define MAX 100000

char hostname[256];

int main(int argc,char **argv)
{
    int rank,size;
    int i;
    int num_procs=0;
    int max_threads=0;
    double sum=0.0;
    double time;

    MPI_Init(&argc,&argv);

        MPI_Comm_rank(MPI_COMM_WORLD,&rank);
        MPI_Comm_size(MPI_COMM_WORLD,&size);

        time=MPI_Wtime();

        #ifdef _OPENMP
        num_procs=omp_get_num_procs();
        max_threads=omp_get_max_threads();
        #pragma omp parallel for reduction(+:sum) num_threads(num_procs) schedule(guided,1)
        #endif
        for(i=0;i<MAX;i++)
        {
                sum+=sin(i);
        }

        time=MPI_Wtime()-time;


        gethostname(hostname,255);
        if(rank==0)
        {
                printf("\"rank\"\t\"size\"\t\"host\"\t\"processors\"\t\"max_threads\"\t\"duration\"\t\"sum\"\n");
                fflush(stdout);
        }

        MPI_Barrier(MPI_COMM_WORLD);

        printf("%d\t%d\t\"%s\"\t%d\t%d\t%.12f\t%.12f\n",rank,size,hostname,num_procs,max_threads,time,sum);

    MPI_Finalize();

    return 0;
}

