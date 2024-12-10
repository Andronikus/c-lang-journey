#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<errno.h>

/**
 * ++++++++++++++++   When fork a process, a new one is created. Child process has
 * | main process |   its own memory space allocated (not shared with parent) and 
 * ++++++++++++++++   a copy of data and file descriptors is made to the child 
 *       ^            process. 
 *       | (fork)
 * ++++++++++++++++*  Fork returns:
 * | child process |    -1: when the operation was not successfully
 * ++++++++++++++++*     0: for the child process
 *                     pid: for the caller process it return the child process
 */                      


int main(int argc, char *argv[]){
    /* fork the main process */
    int id = fork();
    if (id == -1){
        /* fork returns error and errno should contain the error value*/
        printf("error while forking the main process! errno: %d", errno);
        return 1;
    }

    if(id == 0){ 
        printf("child process! \tpid: %d, parent_pid: %d\n", getpid(), getppid());
        sleep(1); // to simulate an action
    }else{
        printf("main process! \tpid: %d, parent_pid: %d\n", getpid(), getppid());
        /**
         * fork caller process should wait for child process to terminate. Otherwise,
         * child process will be bind to another process and resources allocated only
         * be freeded when new parent is terminated (usually a long term process)
         */
        wait(NULL);
    }
    return 0;
}
