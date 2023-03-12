#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int child_process(char name) 
{
    int pid = getpid();
    int rand_num = rand();
    printf("Child process %c, id: %d. Random number: %d.\n", name, pid, rand_num);
    return 0;
}

int main() 
{
    int counter = 0;
    pid_t pid_A, pid_B, pid_M;
    
    pid_A = fork();
    if (pid_A == 0) 
    { 
        child_process('A'); 
        return 0;
    } else if (pid_A < 0) 
    { 
        perror("Error.");
        exit(1);
    }

    pid_B = fork();
    if (pid_B == 0) 
    { 
        child_process('B');
        return 0;
    } else if (pid_B < 0) 
    { 
        perror("Error.");
        exit(1);
    }

    pid_M = fork();
    if (pid_M == 0) 
    {
        child_process('M');
        return 0;
    } else if (pid_M < 0) 
    {
        perror("Error.");
        exit(1);
    }
    
    if(wait(&pid_A))
    {
        counter++;
    }
    if(wait(&pid_B))
    {
        counter++;
    }  
    if(wait(&pid_M))
    {
        counter++;
    }

    printf("Number of child processes successfully executed: %d.\n", counter);
    return 0;
}
