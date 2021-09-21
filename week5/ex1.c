#include <stdio.h>
#include <pthread.h>

void *printingFunc(void* vararg) {
    printf("Thread ID: %lu, OS course is the best\n", pthread_self());
}

int main() {
    const int n;
    scanf("%d", &n);
    pthread_t currentThread;
    for (int i = 0; i < n; i++) {
        pthread_create(&currentThread, NULL, printingFunc, NULL);
        printf("Created thread %lu\n", currentThread);
        pthread_join(currentThread, NULL);//this is fix, that exit current thread before starting nextone
    }
    return 0;
}