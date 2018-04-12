#include <stdio.h>


void main()
{
    FILE *ficheiro; //Cria um apontador do tipo ficheiro
    int contadorA = 0; //Inicia o contador dos As alterados a 0
    int contadorB = 0; //Inicia o contador dos Bs alterados a 0
    char const *nome = "test"; //Parte modular do script, usado para o nome do ficheiro. ".txt" nao e necessario no ubuntu linux
    int caracter; //Define o tipo de dados da variavel caracter a integer.
    ficheiro = fopen(nome, "r+"); //Abre o ficheiro com a variavel nome, neste caso "test"
    while ((caracter = fgetc(ficheiro)) != EOF) //Precorre o ficheiro, caracter a caracter
    {
        if (caracter == 'a') // Se o caracter for a, muda-o para b e incrementa o contador de As alterados
        {
            fseek(ficheiro, -1, SEEK_CUR); //Quando encontrar um caracter 'a', "volta" um caracter atrás para o alterar para 'b'
            fputc('b',ficheiro); //Altera o caracter para 'b'
            fseek(ficheiro, 0, SEEK_CUR); //Avança o cursor para o proximo caracter, dado que este já foi alterado e continua
            contadorA++;
        } else if (caracter == 'b')
        {
            fseek(ficheiro, -1, SEEK_CUR); //Mesmo processo que o anterior, excepto esse procura por 'b' e muda para 'a'
            fputc('a',ficheiro);
            fseek(ficheiro, 0, SEEK_CUR);
            contadorB++;
        }
    }
    fclose(ficheiro);

    printf("O numero de As alterados para Bs sao: %d\n", contadorA);
    printf("O numero de Bs alterados para As sao: %d\n", contadorB);
}