#include "mythread.h"

int main(){

	srand(time(NULL));
	thread_arg data[2];
	pthread_t th[2];
	
	for(int i=0; i<2; i++){
		data[i].key = i;
		data[i].value = rand() % 100;

		printf("Thread %d created!\n", i);
		if(pthread_create(&th[i], NULL, routine, &data[i]) != 0)
			perror("Failed to create the thread!!!\n");
	}

	for(int i=0; i<2; i++)
		pthread_join(th[i], NULL);

	return 0;
}