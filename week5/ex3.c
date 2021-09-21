//
// Created by Павел Бахаруев on 21.09.2021.
//
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct {
	int programCount;
	int storage;
	int *data;
} buffer;

void* producer(void *vararg)
{
	while(1)
	{
		while(buffer.programCount >= buffer.storage);
        if(buffer.programCount >= buffer.storage)
            exit(1);
		buffer.data[buffer.programCount] = buffer.programCount;
		buffer.programCount++;
	}
}
void* consumer(void *vararg)
{
	while(1)
	{
		while(buffer.programCount <= 0);
        if(buffer.programCount <= 0)
		    exit(1);
		buffer.data[buffer.programCount] = 0;
		buffer.programCount--;
	}
}

int main()
{
	buffer.storage = 3;
	buffer.programCount = 0;
	buffer.data = (int*) malloc(buffer.storage * sizeof(int));
	pthread_t producerr;
    pthread_t consumerr;
    pthread_create(&producerr, NULL, producer, NULL);
	pthread_create(&consumerr, NULL, consumer, NULL);
	pthread_join(producerr, NULL);
	pthread_join(consumerr, NULL);
	return 0;
}
