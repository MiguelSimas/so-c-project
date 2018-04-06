#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    printf("Hello world (pid:%d) \n", (int)getpid());
    int rc = fork();
    if (rc < 0)
    { //Fork failed, exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    { //child (new progress)
        printf("Hello, I am child (pid:%d) \n", (int)getpid());
    }
    else
    {
        printf("Hello, I am parent of %d (pid:%d)\n", rc, (int)getpid());
    }
    return 0;
}