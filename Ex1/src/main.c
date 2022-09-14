#include "mythread.h"

int main(){
	pthread_t monit;
	

	if((pthread_create(&monit, NULL, wait, NULL)) != 0){
		printf("Failed to create thread\n");
		exit(EXIT_FAILURE);
	}

	printf("Thread monit initialized successfully !!\n");
	printf("End of the Main !!\n");

	pthread_join(monit, NULL);

	return 0;
}