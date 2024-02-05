#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Elemento{
    char ficha;
    struct Elemento *proximo;
}Elemento;

typedef struct Fila{
    struct Elemento *inicio;
    struct Elemento *fim;
}Fila;

Elemento *aux;
int id = 0;

Fila* cria_fila(){
    Fila* fila = (Fila*) malloc(sizeof(Fila));
    if(fila != NULL){
        fila->fim = NULL;
        fila->inicio=NULL;
    }
    return fila;
}

void Escolha_opcao(Fila *fila){
    Elemento*novo = (Elemento*) malloc(sizeof(Elemento));
    id++;
    char opcao_A = "CNTA";
    char opcao_B = "CRED";
    char opcao_C = "DEBT";  

    int escolha;
    printf("1 - Abertura/Fechamento de conta\n");
    printf("2 - Emprestimo\n");
    printf("3 - Pagamentos\n");
    printf("Escolha seu servico: ");
    scanf("%d", escolha);
    switch (escolha)
    {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    default:
        break;
    }
}

int main(){

}