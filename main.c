#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <string.h>
#include "lista.h"
#include "Retangulo.h"
/**
***
****             @autor                   Reidner sousa
******           @Version                 11
*******          @DataUltimaModificacao   06/01/2022 21:52
*******          @NomeCodigo              Projeto 1
******           @TipoCodigo              Lista encadeada
*****            @CoisasParaFazer         Arrumar lista.c na linha 218 (o problema  é como atualizar o local de guarda o produto sem criar uma nova lista )
****                                      Arrumar a opção numero no 5 e  guarda Material
**/


//Estrutura autorreferenciada

int main()
{

    inicializar();


    //struct produto x;

    /*
    struct produto p1= {112,"congelados","Frango","O frango possui carne de coloração branca",
        "Setor Norte",111
    };

    struct produto p2= {50,"enlatados","Milho","Após abrir deve-se consumir dentro do perido de 30 dias",
        "Setor Sul",28
    };

    struct produto p3= {30,"Vegetais","Maça","maça é um fruto de arvore macieria",
        "Setor Leste",19
    };

    struct produto p4= {333,"Produtos de Limpeza","Desinfetante",
        "são substâncias que são usando na Limpeza",
        "Setor Oeste",30
    };



    struct produto p5= {111,"arroz",NULL,NULL,NULL,NULL};
*/


    //Lista*lop;
    //DigitaStructLocal(lop);
    printf("\n<n>");
    printf("\b<b>");
    printf("\t<t>");
    printf("\f<f>");

    //passa por enquanto
    controleFuncionario();






    /*
        printf("Quinto\n");
        pro1=inserirProdutoTeste(pro1,p5);
        imprimeTodosProduto(pro1);
    */


    /*
        buscaProdutoCodigo(pro1,333);
        ComprarProduto(pro1,p1,10);

        imprimeTodosProduto(pro1);
    */
    printf("\n\n");


    system("pause");
    return 0;


}




/*
strlen Tamanho da string
strcpy copiar uma string
strcat concatenar duas string junta 2 string
strcmp  comapaar duas string
*/
