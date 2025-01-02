#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

/* routine to be executed in parallel */
void* routine(){
    printf("start thread execution\n");
    sleep(2);
    printf("end thread execution\n");
    return NULL;
}

int main (int argc, char* argv[]){
    pthread_t th1, th2;

    if(pthread_create(&th1, NULL, &routine, NULL) != 0){
        return 1;
    }

    if(pthread_create(&th2, NULL, &routine, NULL) != 0){
        return 2;
    }
    
    if(pthread_join(th1, NULL) != 0) {
        return 3;
    }

    if(pthread_join(th2, NULL) != 0) {
        return 4;
    }

    return 0;
}