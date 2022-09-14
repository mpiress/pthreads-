#include "mythread.h"

int main(){
	
	printf("CHAMADA COM PROBLEMA DE CONCORRÊNCIA\n");
	waitP();

	printf("CHAMADA SEM PROBLEMA DE CONCORRÊNCIA\n");
	waitC();


	return 0;
}