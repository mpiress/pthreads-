#ifndef MYTHREAD_H 
#define MYTHREAD_H

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void* routineP(void *arg);
void waitP();

void* routineC(void *arg);
void waitC();


#endif
