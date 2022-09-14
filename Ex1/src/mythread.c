#include "mythread.h"

void * soma(void *arg){
	int aux = 0;

	printf("Thread %s initialized successfully\n", (char *)arg);
	
	while(aux < 10){
		printf("Thread: %s Value:%d\n", (char *)arg, aux);
 		aux += 1;
 	}

 	/*finaliza a função e retorna o argumento void que foi recebido*/
    pthread_exit(arg);
}


void * wait(void *arg){
	
	pthread_t thread_a;
	void *resp;

	if((pthread_create(&thread_a, NULL, soma, (void*)("A"))) != 0){
		printf("Failed to create thread\n");
		exit(EXIT_FAILURE);
	}

	pthread_join(thread_a, &resp);

	printf("Thread %s finalized successfully !!\n", (char*) resp);

	 pthread_exit(arg);
}