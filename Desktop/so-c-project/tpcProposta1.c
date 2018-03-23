#include <stdio.h>
/* 
Resolução da proposta 1

Este script lê um determinado ficheiro txt, procura por caracteres 'a' e 'b' (não é case sensitive e não considera casos especiais, por exemplo 'ã') e troca-os.
Depois, cria e escreve essas alterações em um novo ficheiro.
Finalmente, amostra o número de alterações para cada caso na consola.

Trabalho realizado por Miguel Carreiro Simas para a disciplina de Sistemas Operativos no âmbito
da licenciatura em Informática - Redes e Multimédia, na Universidade dos Açores
Número de aluno : 20162281
*/
void main()
{
    FILE *ficheiro;               //Cria um apontador do tipo ficheiro
    FILE *ficheiro2;              //Ficheiro que irá "receber" o novo texto
    int contadorA = 0;            //Inicia o contador dos As alterados a 0
    int contadorB = 0;            //Inicia o contador dos Bs alterados a 0
    char const *nome = "test";    //Parte modular do script, usado para o nome do ficheiro. ".txt" não é necessario no ubuntu linux
    int caracter;                 //Define o tipo de dados da variável caracter a integer (inteiro).
    ficheiro = fopen(nome, "r"); //Abre o ficheiro com a variável nome, neste caso "test" no modo leitura
    ficheiro2 = fopen("teste2.txt", "w"); //Cria um ficheiro no modo "Write" (escrever)
    while ((caracter = fgetc(ficheiro)) != EOF) //Percorre o ficheiro, caracter a caracter
    {
        if (caracter == 'a') // Se o caracter for a, muda-o para b e incrementa o contador de As alterados
        {
            fseek(ficheiro, 0, SEEK_CUR); //Quando encontrar um caracter 'a', mantem o cursor no caracter e executa os seguintes passos
            fputc('b', ficheiro2);          //Altera o caracter para 'b'
            contadorA++;                   //Incrementa o contador de As alterados
        }
        else if (caracter == 'b')
        {
            fseek(ficheiro, 0, SEEK_CUR); //Mesmo processo que o anterior, excepto esse procura por 'b' e muda para 'a'
            fputc('a', ficheiro2);
            contadorB++;
        }
        else
        {
            fputc(caracter, ficheiro2); //Caso o caracter encontrado não seja 'a' ou 'b', escreve esse caracter
        }
    }
    fclose(ficheiro);
    fclose(ficheiro2);

    printf("O número de As alterados para Bs são: %d\n", contadorA);
    printf("O número de Bs alterados para As são: %d\n", contadorB);
}
