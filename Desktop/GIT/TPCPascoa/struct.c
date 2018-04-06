#include "struct.h"
void main()
{
    struct alunos a1;
    strcpy(a1.nome, "Miguel");
    a1.idade = 21;
    strcpy(a1.universidade, "Universidade dos Açores");
    strcpy(a1.curso, "Informática - Redes e Multimédia");
    a1.anoCurso = 2;
    printf("O nome é %s e a idade é %d.\nEstá na %s a estudar %s, atualmente no %dº ano.", a1.nome, a1.idade, 
    a1.universidade, a1.curso, a1.anoCurso);
}