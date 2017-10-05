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
		printf("El numero total de procesos es: %i\n",p);
	}
	MPI_Finalize();
}
