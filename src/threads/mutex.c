#include<stdio.h>
#include<pthread.h>

// Global variable
int mailbox = 0;

// Global variable of type mutex
pthread_mutex_t mutex;

void* routine(){
    for(int i=0; i<10000; i++){
        // Piece of code (read, add 1, write value) that needs to be protected
        // against reads and writes done by different threads at the same time
        pthread_mutex_lock(&mutex);
        mailbox++;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main(int argc, char* argv[]){
    const int NBR_THREADS = 2;
    pthread_t threads[NBR_THREADS];

    // initialize the mutex
    pthread_mutex_init(&mutex, NULL);

    // create threads
    for(int i=0; i < NBR_THREADS; i++){
        if(pthread_create(&threads[i], NULL, &routine, NULL) != 0){
            printf("error while creating thread %d\n", i);
            return 1;
        }
    }

    // wait for threads to join the main thread
    for(int i=0; i < NBR_THREADS; i++){
        if(pthread_join(threads[i], NULL)){
            printf("error while executing thread join for thread %d\n", i);
            return 2;
        }
    }

    // destroy the mutex
    pthread_mutex_destroy(&mutex);

    // print the value of shared variable
    printf("mailbox value: %d\n", mailbox);

    return 0;
}