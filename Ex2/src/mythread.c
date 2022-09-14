/*
	Compreendendo o problema da concorrência:
	
	- Nesta implementação utilizamos a variável i para produzir
	  um indexador para múltiplas threads. Conduto, a variável é
	  única e seu tempo de atualização vs. execução das threads
	  não é sincrono, o que produzirá um erro de impressão do vetor
	  data.
*/

#include "mythread.h"


// METODOS COM PROBLEMA DE CONCORRÊNCIA //
void* routineP(void *arg){
	int data[10] = {34, 5, 28, 98, 56, 11, 62, 33, 89, 100};
	int index = *(int *)arg;
	
	printf("Index:%d Value:%d \n", index, data[index]);

	/*finaliza a função e retorna o argumento void que foi recebido*/
    pthread_exit(arg);
}

void waitP(){

	pthread_t th[10];
	
	for(int i=0; i<10; i++){
		if(pthread_create(&th[i], NULL, &routineP, &i) != 0){
			perror("Failed to create thread");
		}
	}

	for(int i=0; i<10; i++){
		if(pthread_join(th[i], NULL) != 0){
			perror("Failed to join threads");
		}
	}

}
///////////////////////////////////////////////////////////////]

// METODOS SEM PROBLEMA DE CONCORRÊNCIA //
void* routineC(void *arg){
	int data[10] = {34, 5, 28, 98, 56, 11, 62, 33, 89, 100};
	int index = *(int *)arg;
	
	printf("Index:%d Value:%d \n", index, data[index]);
	free(arg);

	/*finaliza a função e retorna o argumento void que foi recebido*/
    pthread_exit(arg);
}



void waitC(){

	pthread_t th[10];
	
	for(int i=0; i<10; i++){
		int *a = (int*) malloc(sizeof(int));
		*a = i;
		if(pthread_create(&th[i], NULL, &routineC, a) != 0){
			perror("Failed to create thread");
		}
	}

	for(int i=0; i<10; i++){
		if(pthread_join(th[i], NULL) != 0){
			perror("Failed to join threads");
		}
	}

}
