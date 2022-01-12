


/*
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

*/

typedef struct lista Lista;

typedef struct produto Produto;

/**Teste não funciono **/
/*
struct produto p6={322,"Produtos de Teste","TEste",
    "são substâncias que são usando na Limpeza",
    "Setor De Teste",33};

    */



//Função que mostra a opçções
/**         @numeroFuncao 1
*
*
*/
int  adm();


//Função que faz o cálculo dos estoque mínimos
float estoqueMin( int tempReposicao, int tempo ,int consumoMedio1);

//Função que faz o cálculo dos consumoMedio
float consumoMedio( int consItens, int tempo );

//Função que faz o cálculo Suprimento
float calLoteSuprimento(int custoPedido , int Demanda, int CustArmazena);

//Função que cálcula o estoqueMax
float estoqueMax(int estoqueMin1 , int  loteReposicao);

//Função que verifica se tem produto no estoque é fazer um descremento com
// base na quantidade comprada
void EmitirPedido(Lista * l, Produto v, int x);

//Função que emitir todos os produtos
void imprimeTodosProduto(Lista *l);

//Função que identificar o produto
Lista* buscaProdutoCodigo (Lista* l, int v);

//Função definir onde vai ser guardando uma variavel
Lista * GuardarMaterial(Lista *l,int codigo3,char local1[20]);

//Função que inserir Produto
Lista *inserirProdutoTeste(Lista * l, Produto i);

//Reservar materias mediante solicitações
void ComprarProduto(Lista * l,int codigo,int x);


/**Fim produtos ***/

Lista* inicializaE (void);

Lista* insereE (Lista* l, int i);

/* função imprime: imprime valores dos elementos */
void imprimeE (Lista* l);


/* função vazia: retorna 1 se vazia ou 0 se não vazia */

/* função busca: busca um elemento na lista */
Lista* buscaE (Lista* l, int v);


/* função retira: retira elemento da lista */
Lista* retiraE (Lista* l, int v);

void liberaE (Lista* l);

/* função auxiliar: cria e inicializa um nó */
Lista* criaE (int v);


Lista *inserirProdutoLocal(Lista * localLista,Produto ilocal);

int igual (Lista* l1, Lista* l2);



