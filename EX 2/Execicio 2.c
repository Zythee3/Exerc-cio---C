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
int id = 0, hora = 9, min = 0, rest = 30, Haux = 0;

Fila* cria_fila(){
    Fila* fi = (Fila*) malloc(sizeof(Fila));
    if(fi != NULL){
        fi->fim = NULL;
        fi->inicio = NULL;
    }
    return fi;
}

void adicionar_elemento(Fila *fi, int *id, int *hora, int *min, int *rest){
    (*id)++;
    (*rest)--;
    //Adiciona na fila
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
    printf("O cliente numero %d, foi inserido na fila de espera.",*id);
    getch();

    //Ajusta relógio
    if(*min == 40){
        (*hora)++;
        *min = 0;
    }else{
        *min += 20;
    }
}
void consulta_fila(Fila *fi){
    if(fi->inicio == NULL){
        printf("\nNao ha clientes na fila. Tente novamente mais tarde!");
    }else{
        aux = fi->inicio;
        do{
            printf(" %d ", aux->num);
            aux = aux->prox;
        } while(aux != NULL);
    }
    getch();
}	

void atender_fila(Fila *fi){
    if(fi->inicio == NULL){
        printf("\nFila Vazia!!");
    }else{
        aux = fi->inicio;
        printf("Cliente: %d, atendido!", fi->inicio->num);
        fi->inicio = fi->inicio->prox;
        free(aux);
    }
    getch();
}

void esvaziar_fila(Fila *fi){
    if( fi->inicio == NULL ){
        printf("\n\nNao ha clientes na fila. Tente novamente mais tarde!");
    }else{
        aux = fi->inicio;
        do{
            fi->inicio = fi->inicio->prox;
            free(aux);
            aux = fi->inicio;
        }while(aux != NULL);
    }
    printf("O expediente foi encerrado.");
    getch();
}

void horario_ajuste(int hora, int min){
    //Calcular relogio
        if(hora == 9 && min == 0){
            printf("Horario Atual: %d%d:%d%d\t",Haux,hora,min,Haux);
        }
        else if (hora == 9)
        {
            printf("Horario Atual: %d%d:%d\t",Haux,hora,min);
        }
        else if (min == 0)
        {
            printf("Horario Atual: %d:%d%d\t",hora,min,Haux);
        }else{
            printf("Horario Atual: %d:%d\t",hora,min);
        }
}

int main(){
    Fila *fi = cria_fila();
    int input;
    do{
        printf("\n\n------------ Sistema de Fichas -------------\n\n");
        horario_ajuste(hora,min);
        printf("Fichas Restantes: %d\n\n1. Adicionar Cliente\n2. Atender Cliente\n3. Consultar Fila\n4. Encerrar Expediente",rest);
        printf("\n\nEscolha uma das opcoes acima: ");
        scanf("%d",&input);
        switch (input)
        {  
        case 1:
            if(hora != 19){
                adicionar_elemento(fi, &id,&hora,&min, &rest);
            }else{
                printf("\nO atendimento nao pode ser realizado pois o horario de atendimento foi encerrado (19:00).");
                getch();
            }

            break;
        case 2:
            if (fi->inicio == NULL)
            {
                printf("\n\nNao ha clientes na fila. Tente novamente mais tarde!");
                getch();
            }else{
                atender_fila(fi);
            }
            break;
        case 3:
            consulta_fila(fi);
            break;
        case 4:
            esvaziar_fila;
            break;    

        default:
            break;
        }

    }while (input != 0);
    printf("\nFim");
    
    
}