#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t semaphore;

void *thread_function(void *arg) {
    int i;
    for (i = 0; i < 10; i++) {
        sem_wait(&semaphore);
        printf("Mensaje desde el hilo: Iteración %d\n", i);
        sem_post(&semaphore);
    }
        return NULL;
}

int main() {
    sem_init(&semaphore, 0, 1);

    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, thread_function, NULL);
    pthread_create(&thread2, NULL, thread_function, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    sem_destroy(&semaphore);

    return 0;
}

