#include <stdio.h>
#include "mpi.h"
#include <stdlib.h>  

int main(int argc,char *argv[]){
	int circle, circleTotal, maxVal;
	int range, start, end, size, rank;	

	maxVal=1e9;

	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	// Defina aqui el segmento que debe procesar una tarea
	// El inicio del segmento en la variable 'start', el fin del segmento
	// la variable 'end'
	srand(time(NULL));
	
	circle = 0;
	range = maxVal / size;
	start = (range * rank)+1;
	end = (range * (rank+1));
	printf("El rango es: %i\n",rank);
        for (int i = start; i <= end; i ++) {
            double x = ((double)rand()) / ((double)RAND_MAX);
            double y = ((double)rand()) / ((double)RAND_MAX);
            if (x * x + y * y <= 1.0) circle ++;
        }
 	printf("La suma de circulo es: %i\n",circle);
	printf("Comenzo %i , termina %i\n",start,end);

        //printf("%i :  %f\n",N[rank],(double)circle / N[rank] * 4.0);

	/*int range = maxVal / size;
	start = (range * rank)+1;
	end = (range * (rank + 1));
    	sum = 0;
	printf("rank %i tiene start %i y end %i\n",rank,start,end);
    	for(i=start; i<= end; i++){
    		sum = sum +i;
    	}*/

	// Utilice la funcion 'MPI_Reduce' para guardar en la variable 
	// 'sumTotal' la suma parcial de todos las tareas
	MPI_Reduce(&circle, &circleTotal, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

	if(rank==0){
	  printf("El total de la suma es: %i\n",circleTotal);
	  printf("%i :  %f\n",maxVal,(double)circle / maxVal * 4.0);
	}

	MPI_Finalize();
	
	return 0;
}



