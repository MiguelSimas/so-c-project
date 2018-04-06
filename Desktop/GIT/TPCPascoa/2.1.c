#include "struct.h"
void main()
{
    struct alunos a1;
    struct alunos a2;
    struct alunos a3;
    struct alunos a4;
    struct alunos vetor_alunos[4];
    vetor_alunos[0] = a1;
    vetor_alunos[1] = a2;
    vetor_alunos[2] = a3;
    vetor_alunos[3] = a4;
    char temp[100];
    for (int i = 0; i <= 3; i++)
    {
        printf("Nome do aluno %d:\n ", i+1);
        scanf("%s", vetor_alunos[i].nome);
        printf("Idade do aluno %d:\n ", i+1);
        scanf("%s", temp);
        vetor_alunos[i].idade = atoi(temp); //Converte o conteúdo da string recebida em inteiro.
    }

    for (int i = 0; i<=3; i++){
        printf("O aluno %d chama-se %s e tem %d anos.\n", i+1, vetor_alunos[i].nome, 
        vetor_alunos[i].idade);
    }
}