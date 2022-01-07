#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include "lista.h"
#include <string.h>


//struct para calcula o tamanho

/*
struct lista{
    int tamanho;
    produto info;
    struct lista* lista;
};
*/


struct produto
{
    int codigo;
    char categoria[30];
    char nome[30];
    char descricao[70];
    char localArmaze[30];
    int qtdEstoque;

    int connsumoMedio;
    int tempReposicao;
    int tempo;

};
struct lista
{
    struct   produto info;
    struct lista*prox;
};



int  adm()
{
    int opc;

    printf("________________Seleciones as op��es ____________\n\n");
    printf("1 Inserir \n");
    printf("2 Procura Produto pelo codigo\n");
    printf("3 Mostra todos os elementos no estoque\n \n");
    printf("4 Reservar materiais mediante solicita��es\n");
    printf("5 Decidir onde vai guarda o produto\n");
    printf("6 Imprimir os valores de um produto\n");
    printf("7 sai do sistema \n ");

    scanf("%d",&opc);

    return opc;

}

/**teste**/

Lista *  AtualizarDados( Lista *recebe ,int codigo , char setorEsco[20])
{

    Produto p7;
    fflush(stdin);
    printf("Digite o local de Armazenamento(Setor sul , Setor norte ,Setor Oeste e Setor Leste)\n");
    fgets(p7.localArmaze,30, stdin);

    fflush(stdin);



    return inserirProdutoLocal(recebe,p7);
}

Lista *  DigitaStruct( Lista *recebe3 )
{

    Produto p1;
    printf(" Int\n");
    printf("Digite o codigo\n");
    scanf("%d",&p1.codigo);
    printf("Digite o consumoMedio\n");
    scanf("%d",&p1.connsumoMedio);
    printf("Digite a quantidade em Estoque\n");
    scanf("%d",&p1.qtdEstoque);

    printf("String\n");

    printf("\t____________Digite o categoria_______________\n\n");
    printf("\tEnlatados\n");
    printf("\tProdutos de Limpeza\n");
    printf("\tComest�vel \n");
    printf("\tGelados \n");

    fflush(stdin);
    fgets(p1.categoria,30, stdin);

    fflush(stdin);
    printf("Digite a descri��o\n");
    fgets(p1.descricao,70, stdin);

    fflush(stdin);
    printf("\t____________Digite o local de Armazenamento_______________\n\n");
    printf("\tSetor Sul\n");
    printf("\tSetor Norte\n");
    printf("\tSetor Oeste \n");
    printf("\tSetor Leste \n");

    fgets(p1.localArmaze,30, stdin);

    fflush(stdin);
    printf("Digite o nome do produto  \n");
    fgets(p1.nome,30, stdin);

    fflush(stdin);

    return inserirProdutoTeste(recebe3,p1);





}





/*N�o estou usando*/
Lista*AdicionaProdutoumporUm(Lista * rebvar,Produto p1, Produto p2 )

{
    Lista *recebe6;
    int opcao1;
    int opcao2;
    printf("________________Seleciones as op��es ____________\n\n");
    printf("1 para Inserir algum produto \n");
    printf("2 para fecha o programa \n");
    scanf("%d",&opcao1);
    if(opcao1 ==1)
    {
        printf("\n Qual produto deixa insirir \n");
        printf("1 para Frango  \n");
        printf("2 para Ma�a\n");
        printf("3 para Milho\n");
        printf("4 para Desinfetante\n");
        scanf("%d",&opcao2);
        if(opcao2==1)
        {
            recebe6=inserirProdutoTeste(recebe6,p1);
            return recebe6;
        }
        if(opcao2==2)
        {
            recebe6=inserirProdutoTeste(recebe6,p2);
            return recebe6;
        }
    }
    else
    {
        printf("\n Fim do adiciona um por um ");
        return 0;
    }


}
/*FAZ TUDO*/
void controleFuncionario()

{
    Lista *creb=inicializaE();

    int reposta;
    do
    {
        reposta=adm();

        if(reposta==1)

        {

            creb=DigitaStruct(creb);
        }

        if(reposta==2)
        {
            int valorCodigo;
            printf("\n Digite o codigo do produto \n");
            scanf("%d",&valorCodigo);
            buscaProdutoCodigo(creb,valorCodigo);

        }
        if(reposta==3)
        {
            imprimeTodosProduto(creb);
        }
        if(reposta==4)
        {
            int qtdProduto;
            int codigo;
            printf("\nDigite a quantidade de produto que deixa comprar(reserva) \n");
            scanf("%d",&qtdProduto);
            printf("Digite o codigo do produto\n");
            scanf("%d",&codigo);

            ComprarProduto(creb,codigo,qtdProduto);
        }
        if(reposta==5)
        {
            //erro aqui
            int codigo3;
            char local1[20];
            printf("op��o 5\n");
            printf("Digite o codigo \n");
            scanf("%d",&codigo3);

            if(codigo3==creb->info.codigo){
                printf("Digite onde deixa guarda o produto \n");
                //scanf("%s",&local1); da um overflow

                creb=GuardarMaterial(creb,codigo3,local1);
            }
            else if(codigo3=!creb->info.codigo){
                printf("N�o esta funcionasdo2");
            }

        }

        if(reposta==6)
        {
            int codigo2;
            printf("Digite o codigo do produto\n");
            scanf("%d",&codigo2);


            if(codigo2==creb->info.codigo){
                printf("Esta funcionado \n");
                imprimeProdutoCodigo(creb,codigo2);
            }
            else{
                printf("N�o esta fucionando ");
            }

        }

    }

    while(reposta!=7);
}

/**TEste**/


Lista *inserirProdutoLocal(Lista * localLista,Produto ilocal)
{
    Lista *novo=(Lista*)malloc (sizeof(Lista));



    strcpy(novo->info.localArmaze,ilocal.localArmaze);
    novo->prox=localLista;

    return novo;
}


//*Tem um erro algo inserir GuardaMaterial ele criar uma nova lista *
Lista *  GuardarMaterial(Lista *l,int codigo3, char local[20] )
{

    Lista*recebe;


    for (recebe = l; recebe->info.codigo != codigo3; recebe = recebe->prox);
    if(recebe==NULL)
    {
        printf("N�o cadastrado");
        return ;
    }





}


float estoqueMin( int tempReposicao, int tempo,int consumoMedio1)
{

    return (consumoMedio1*tempReposicao)/tempo;
}

float consumoMedio( int consItens, int tempo )
{

    return consItens/tempo;
}

float calLoteSuprimento(int custoPedido, int Demanda, int CustArmazena)
{

    return sqrt((2*custoPedido*Demanda)/CustArmazena);
}

float estoqueMax(int estoqueMin1, int  loteReposicao)
{
    return estoqueMin1+loteReposicao;
}


//typedef struct lista Lista;

/* fun��o de inicializa��o: retorna uma lista vazia */
Lista* inicializaE (void)
{
    return NULL;
}




Lista *inserirProdutoTeste(Lista * l,Produto i)
{
    Lista *novo=(Lista*)malloc (sizeof(Lista));

    strcpy(novo->info.categoria,i.categoria);
    novo->info.codigo=i.codigo;
    novo->info.connsumoMedio=i.connsumoMedio;
    strcpy(novo->info.descricao,i.descricao);
    strcpy(novo->info.localArmaze,i.localArmaze);
    strcpy(novo->info.nome,i.nome);
    novo->info.qtdEstoque =i.qtdEstoque;
    novo->info.tempo= i.tempo;
    novo->info.tempReposicao=i.tempReposicao;
    novo->prox=l;

    return novo;
}

Lista *inserirProdutoTesteM(Lista * l, Produto i)
{

    Produto * prod =(Produto*)malloc(sizeof(Produto));
    Lista*novo =(Lista*)malloc(sizeof(Lista));

    novo->info=i;
    novo->prox =l;

    return novo;

}

/****Fim do teste ****/

Lista* inserirProduto( Lista * l, Produto i)
{
    Lista*novo =(Lista*)malloc(sizeof(Lista));

    novo->info =i;
    novo->prox=l;
    return novo;



}

void ComprarProduto(Lista * l,int codigo,int x)
{
    Lista *p;
    for(p = l; p->info.codigo != codigo; p = p->prox);

    if(p==NULL)
    {
        printf("N�o cadastrado\n");
        return ;
    }

    printf("produto :%c quantidade : %d \n", p->info.nome,x );
    p->info.qtdEstoque+=x;

}

void EmitirPedido(Lista * l, Produto v, int x)
{
    Lista *p;

    for(p = l; p->info.codigo != v.codigo; p = p->prox);

    if(p==NULL)
    {
        printf("N�o cadastrado");
        return ;
    }
    if(p->info.qtdEstoque<x)
    {
        printf("Estoque insuficiente");
        return ;
    }
    printf("produto :%c quantidade : %d \n", p->info.nome,x );
    p->info.qtdEstoque-=x;

}


void imprimeTodosProduto(Lista *l)
{

    Lista*recebe;


    for (recebe = l; recebe != NULL; recebe = recebe->prox)
    {
        printf("_______________PRODUTOS___________________\n");
        printf("  codigo     : %d \n",recebe->info.codigo);
        printf("  nome       : %s \n",recebe->info.nome);
        printf("  descricao  : %s \n",recebe->info.descricao);
        printf("  Armaze     : %s \n",recebe->info.localArmaze);
        printf("  qtdEstoque : %d \n",recebe->info.qtdEstoque);


    }
}




// arrrumei
void imprimeProdutoCodigo (Lista *l,int codigo)
{
    Produto v;
    Lista*rece;

    // for( p = l ;  p->info.codigo    != v.codigo; p      = p->prox);


    for (rece = l; rece->info.codigo  != codigo; rece = rece->prox);

    if(rece==NULL)
    {
        printf("N�o cadastrado");
        return ;
    }

    // printf("produto :%c quantidade : %d \n", p->info.nome,x );
    printf("_______________PRODUTOS___________________\n");
    printf("  codigo     : %d \n",rece->info.codigo);
    printf("  nome       : %s \n",rece->info.nome);
    printf("  descricao  : %s \n",rece->info.descricao);
    printf("  Armaze     : %s \n",rece->info.localArmaze);
    printf("  qtdEstoque : %d \n",rece->info.qtdEstoque);


}

/* fun��o imprime: imprime valores dos elementos */
void imprimeProduto (Produto v)
{

    printf("_______________PRODUTOS___________________\n");
    printf("  codigo     : %d \n",v.codigo);
    printf("  nome       : %s \n",v.nome);
    printf("  descricao  : %s \n",v.descricao);
    printf("  Armaze     : %s \n",v.localArmaze);
    printf("  qtdEstoque : %d \n",v.qtdEstoque);


}


/* fun��o vazia: retorna 1 se vazia ou 0 se n�o vazia */
int vaziaE (Lista* l)
{
    if (l == NULL)
    {

        return 1;// vazio
    }
    else
    {

        return 0; // n�o vazio
    }
}


/* fun��o vazia: retorna 1 se vazia ou 0 se n�o vazia */
int vazia_compactada (Lista* l)
{
    return (l == NULL);
}

/* fun��o busca: busca um elemento na lista */
//Identificar produto
Lista* buscaProdutoCodigo (Lista* l, int v)
{

    Lista* p;


    for (p=l; p!=NULL; p=p->prox)
    {
        if (p->info.codigo == v)
        {
            printf("info %d encontrada \n",v);
            //deu certo mas ele pode puxa duas struct .

            imprimeProduto(p->info);

            return p;
        }
    }
    printf("info %d n�o encotrada =NULL\n",v);
    return NULL; /* n�o achou o elemento */
}



/* fun��o retira: retira elemento da lista */
Lista* retiraPeloCodigo (Lista* l, int v)
{
    Lista* ant = NULL; /* ponteiro para elemento anterior */
    Lista* p = l; /* ponteiro para percorrer a lista*/
    /* procura elemento na lista, guardando anterior */
    while (p != NULL && p->info.codigo != v)
    {
        ant = p;
        p = p->prox;
    }
    /* verifica se achou elemento */
    if (p == NULL)
    {
        return l; /* n�o achou: retorna lista original */
    }
    /* retira elemento */
    if (ant == NULL)
    {
        /* retira elemento do inicio */
        l = p->prox;
    }
    else
    {
        /* retira elemento do meio da lista */
        ant->prox = p->prox;
    }
    free(p);
    return l;
}

void liberaE (Lista* l)
{
    Lista* p = l;
    while (p != NULL)
    {
        Lista* t = p->prox; /* guarda refer�ncia para o pr�ximo elemento
*/
        free(p); /* libera a mem�ria apontada por p */
        p = t; /* faz p apontar para o pr�ximo */
    }
}


/* fun��o auxiliar: cria e inicializa um n� */
Lista* criaProduto (Produto v)
{
    Lista* p = (Lista*) malloc(sizeof(Lista));
    p->info = v;
    return p;
}
/* fun��o insere_ordenado: insere elemento em ordem */
Lista* insere_ordenadoProduto (Lista* l, Produto v)
{
    Lista* novo = criaProduto(v); /* cria novo n� */
    Lista* ant = NULL; /* ponteiro para elemento anterior */
    Lista* p = l; /* ponteiro para percorrer a lista*/
    /* procura posi��o de inser��o */
    while (p != NULL && p->info.codigo < v.codigo)
    {
        ant = p;
        p = p->prox;
    }
    /* insere elemento */
    if (ant == NULL)   /* insere elemento no in�cio */
    {
        novo->prox = l;
        l = novo;
    }
    else   /* insere elemento no meio da lista */
    {
        novo->prox = ant->prox;
        ant->prox = novo;
    }
    return l;
}
/******************************************************************************************
                                FUN��ES RECURSIVAS
*****************************************************************************************/
/* Fun��o imprime recursiva */
void imprime_rec (Lista* l)
{
    if (vaziaE(l))
    {
        return;
    }
    /* imprime primeiro elemento */
    printf("info: %d\n",l->info);
    /* imprime sub-lista */
    imprime_rec(l->prox);
}

/* Fun��o retira recursiva */
Lista* retira_rec (Lista* l, Produto v)
{
    if (vaziaE(l))
        return l; /* lista vazia: retorna valor original */
    /* verifica se elemento a ser retirado � o primeiro */
    if (l->info.codigo == v.codigo)
    {
        Lista* t = l; /* tempor�rio para poder liberar */
        l = l->prox;
        free(t);
    }
    else
    {
        /* retira de sub-lista */
        l->prox = retira_rec(l->prox,v);
    }
    return l;
}
void libera_rec (Lista* l)
{
    if (!vaziaE(l))
    {
        libera_rec(l->prox);
        free(l);
    }
}
/*********************************************88
            Exercicio
*******************************/

/***
fun�a� que verifica se duas lista sao iguais .
Esta fun��o apresenta bugs . Ao executar se todos os elementos forem diferentes ela funciona bem pois vai dizer que n�o iguais
.Por outro lado se encontra uma elemento igual ela vai dizer que todos s�o verdadeiro apesar de serem falso .
***/

// funcionar bem mas  se o primeiro elemento for diferente ou igual nao fazer diferen�a

int tamanho(Lista* l)
{
    int count=0;
    Lista *p;
    p=l;
    while(p != NULL)
    {
        p = p->prox;
        count++;
    }
    return count;
}

