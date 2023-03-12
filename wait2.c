#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() 
{
    int status;
    pid_t pid_A, pid_B, pid_M;

    pid_A = fork();
    if( pid_A == 0 )
    {
        sleep(10);
        printf("A id: %d\n", getpid());
        return 10;

    } else 
    
    pid_B = fork();
    if( pid_B == 0 )
    {
        printf("B id: %d\n", getpid());
        return 0;
    } else

    pid_M = fork();
    if( pid_M == 0 )
    {
        sleep(3);
        printf("M id: %d\n", getpid());
        return(3);
    }
    
    waitpid(pid_M, &status, 0);
    printf("El proceso M terminó con valor de retorno: %d.\n", WEXITSTATUS(status));
    waitpid(pid_A, &status, 0);
    printf("El proceso A terminó con valor de retorno: %d.\n", WEXITSTATUS(status));
    waitpid(pid_B, &status, 0);
    printf("El proceso B terminó con valor de retorno: %d.\n", WEXITSTATUS(status));
}
