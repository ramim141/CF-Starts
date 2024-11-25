#include <stdio.h>
#include <windows.h>
#include <pthread.h>

void* threadFunction(void* arg) {
    printf("Thread ID: %ld\n", pthread_self());
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, threadFunction, NULL);
    pthread_create(&thread2, NULL, threadFunction, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}
