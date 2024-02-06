#include <stdio.h>

struct Elemento{
    int dado;
    struct Elemento *prox;
}Elemento;

struct Fila{
    struct Elemento *inicio;
    struct Elemento *fim;
    int tamanho;
}Fila;

Fila *criar_fila(){
    Fila* fi= malloc(sizeof(Fila));
    if (fi != NULL){
        fi-> fim = NULL;
        fi-> inicio = NULL;
    }
    return fi;
}

void insere_fila_a(Fila *fi,int ficha){
    Elemento *novo = (Elemento*) malloc(sizeof(Elemento));
    novo->ficha = ficha;
    novo->prox = NULL;

    if(fi->fim == NULL){
        fi->inicio = novo;
        fi->fim = novo;
    }else{
        fi->fim->prox = novo;
        fi->fim = novo;
    }
    fi->tamanho++;
}


