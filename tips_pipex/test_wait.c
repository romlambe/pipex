#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    pid_t pid;

    pid = fork(); // Fork a new process
    if (pid == -1)
    {
        perror("fork"); // If fork fails, output the error
        exit(EXIT_FAILURE);
    }
    else if (pid == 0) // Child process
    {
        printf("I am the child process.\n");
        sleep(2); // Child process sleeps for 2 seconds
        exit(EXIT_SUCCESS); // Exit child process
    }
    else // Parent process
    {
        printf("I am the parent process.\n");
        wait(NULL); // Parent process waits for the child to terminate
        //int status;
        //waitpid(pid, &status, 0);
        printf("Child process terminated after a 2s delay.\n");
    }

    return (EXIT_SUCCESS);
}
