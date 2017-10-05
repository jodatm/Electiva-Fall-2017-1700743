#include <stdio.h>
#include <string.h>
#include <mpi.h>

int main(int argc, char **argv) {
	int my_rank, p, tag = 0;
	char msg[20];
	MPI_Status status;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	MPI_Comm_size(MPI_COMM_WORLD, &p);
	if (my_rank == 0) {
		printf("Yo soy el maestro y existen %i procesos corriendo\n",p);		
	} else {
		printf("Yo soy un proceso con identificador %i de %i procesos en ejecucion\n",my_rank,p);
	}
	MPI_Finalize();
}
