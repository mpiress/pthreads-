#ifndef MYTHREAD_H 
#define MYTHREAD_H

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include <time.h>

typedef struct{
	int key, value; 
}thread_arg, *ptr_thread_arg;

void* routine(void *arg);

#endif
