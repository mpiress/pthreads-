/*
	Utilizando pthreads com passagem de múltiplos parâmetros.
*/

#include "mythread.h"


void* routine(void *arg){
	ptr_thread_arg targs = (ptr_thread_arg)arg;

	for(int i=0; i<targs->value; i++)
		printf("Thread %ld key %d value: %d \n", pthread_self(), targs->key, i);

	pthread_exit(arg);
}