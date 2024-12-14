#include<stdio.h>
#include<stdlib.h>  // For srand and rand
#include<time.h>    // For time

/**
 * The srand function seeds the random number generator with a specific value. In this case, the current time (seconds) is used as the seed. 
 * Seeding with time(NULL) ensures that the random numbers generated by rand() will vary between runs of the program otherwise the same random values will be produced.
 */

int main(int argc, char *argv[]){

    // Get the current time in seconds since Epoch time - 1970-01-01 00:00:00 +0000 (UTC)
    time_t timeSecondsFromEpoch = time(NULL);
    // Seed the random number generator with the current time
    srand(timeSecondsFromEpoch);

    printf("rand number: %d\n", rand());
    return 0;
}
