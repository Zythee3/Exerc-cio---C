#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Elemento{
    int num;
    struct Elemento *prox;
}Elemento;

typedef struct Fila{
    struct Elemento *inicio;
    struct Elemento *fim;
}Fila;


Elemento *aux;
int id = 0, hora = 9, min = 0;

Fila* cria_fila(){
    Fila* fi = (Fila*) malloc(sizeof(Fila));
    if(fi != NULL){
        fi->fim = NULL;
        fi->inicio = NULL;
    }
    return fi;
}

void insere_elemento(Fila *fi, int *id){
    Elemento*novo =(Elemento*) malloc(sizeof(Elemento));
    novo->num = *id;
    novo->prox = NULL;
    if(fi->inicio == NULL){
        fi->inicio = novo;
        fi->fim = novo;
    }else{
        fi->fim->prox = novo;
        fi->fim = novo;
    }
    getch();
}
void consulta_fila(Fila *fi){
    if(fi->inicio == NULL){
        printf("\nFila Vazia!!");
    }else{
        aux = fi->inicio;
        do{
            printf(" %d ", aux->num);
            aux = aux->prox;
        } while(aux != NULL);
    }
    getch();
}	

void remove_elemento_fila(Fila *fi){
    if(fi->inicio == NULL){
        printf("\nFila Vazia!!");
    }else{
        aux = fi->inicio;
        printf("%d removido!", fi->inicio->num);
        fi->inicio = fi->inicio->prox;
        free(aux);
    }
    getch();
}

void esvazia_fila(Fila *fi){
    if( fi->inicio == NULL ){
        printf("\nFila Vazia!!");
    }else{
        aux = fi->inicio;
        do{
            fi->inicio = fi->inicio->prox;
            free(aux);
            aux = fi->inicio;
        }while(aux != NULL);
        printf("\nFila Esvaziada!!");
    }
    getch();
}

void adicionarElemento(Fila *fi, int *id, int *hora, int *min){
    (*id)++;
    printf("O cliente numero %d, foi inserido na fila de espera.",*id);
    insere_elemento(fi, id);
    if(*min == 40){
        (*hora)++;
        *min = 0;
    }else{
        *min += 20;
    }
    
    printf("voltou");
}

int main(){
    Fila *fi = cria_fila();
    int input;

    do{

        
        printf("\n\nHorario: %d:%d\nFila Atual: %d\n1. Adicionar Cliente\n2. Atender Cliente\n3. Encerrar Espediente", hora,min);
        
        printf("\nEscolha uma opcao: ");
        scanf("%d",&input);
        switch (input)
        {
            
        case 1:
            

            if(hora != 19){
                adicionarElemento(fi, &id, &hora,&min);
            }
            break;
        case 2:
            if (fi->inicio == NULL)
            {
                printf("Nao ha clientes para ser atendidos.");
            }else{
                remove_elemento_fila(fi);
            }
            break;
        
        default:
            break;
        }

    }while (input != 0);
    printf("\nFim");
    
    
}