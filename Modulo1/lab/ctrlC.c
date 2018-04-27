#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
void trata_ctrl_c(int signum)
{
    char buffer[2];
    /* reinstala o handler...*/
    if (signal(SIGINT, trata_ctrl_c) == SIG_ERR)
    {
        perror("Erro ao instalar signal handler");
    }
    printf("Signal %3d. Deseja terminar?", signum);
    fgets(buffer, 2, stdin);
    if (buffer[0] == 's')
    {
        exit(1);
    }
    else
    {
        printf("\n");
    }
}
int main()
{
    int num = 2;
    /* instalar hander para o signal SIGINT */
    if (signal(SIGINT, trata_ctrl_c) == SIG_ERR)
    {
        perror("Erro ao instalar signal handler");
    }
    for (;;)
    {
        printf("\r % 7d", num++);
    }
    exit(0);
}