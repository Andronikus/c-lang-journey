#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#define NBR_PRIMES 10
#define NBR_THREADS 2

/**
 * Use threads calculate the sum of an array of values
 */

unsigned int primes[NBR_PRIMES] = {2,3,5,7,11,13,17,19,23,29};

void* sum_values(void* arg)
{
    if(arg == NULL) return NULL;
    
    unsigned int start_idx = *(unsigned int*) arg;

    unsigned int sum = 0;
    for(int i=0; i<NBR_PRIMES/NBR_THREADS; i++){
        sum += primes[start_idx + i];
    }

    /* return the value using the same reference of arg to avoid
       allocating  memory in a place where will not be free 
    */
    *(unsigned int*) arg = sum;
    return arg;
}

int main(int argc, char* argv[])
{
    pthread_t th[NBR_THREADS];

    // thread creation
    for(int i=0; i < NBR_THREADS; i++)
    {
        unsigned int* arr_idx = malloc(sizeof(unsigned int));

        if(arr_idx == NULL)
        {
            printf("Something went wrong while allocating memory\n");
            return 1;
        }

        *arr_idx = i * (NBR_PRIMES/NBR_THREADS);
        if(pthread_create(&th[i], NULL, &sum_values, arr_idx) != 0)
        {
            printf("Something went wrong while creating threads\n");
            free(arr_idx);
            return 2;
        }
    }

    // thread join
    unsigned int total = 0;
    for(int i=0; i < NBR_THREADS; i++)
    {
        unsigned int* sum;
        if(pthread_join(th[i], (void**)&sum) != 0) // 0x00001F (28) | 0x00001F (81)
        {
            printf("Something went wrong while threads join. error number\n");
            return 2;
        }
        total += *sum;
        
        if(sum != NULL) free(sum);
    }
    
    printf("Sum of the first %d primes: %u\n", NBR_PRIMES, total);

    return 0;
}