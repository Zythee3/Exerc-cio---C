#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// registro que reprensentará cada elemento da pilha
struct Elemento
{
	int nome;
	struct Elemento *prox;
};
typedef struct Elemento Elemento;

// registro do tipo Fila contento dois ponteiros do tipo nó para controlar a fila
struct Fila
{
	struct Elemento *inicio; // aponta para o elemento do início da fila
	struct Elemento *fim;	 // aponta para o elemento do fim da fila
};
typedef struct Fila Fila;

// ponteiro auxiliar
Elemento *aux;

Fila *cria_fila()
{
	// alocação do ponteiro li para controlar a lista
	Fila *fi = (Fila *)malloc(sizeof(Fila));
	if (fi != NULL)
	{
		// a fila inicia-se vazia, portanto inicio e fim são iguais a NULL
		fi->fim = NULL;
		fi->inicio = NULL;
	}
	return fi;
}

void insere_elemento(Fila *fi, char *ficha)
{
	// a cada inserção alocamos dinamicamente um espaço para um novo elemento
	Elemento *novo = (Elemento *)malloc(sizeof(Elemento));

	novo->nome = ficha;
	novo->prox = NULL;
	// caso a fila esteja vazia, o elemento inserido será o primeiro e o último
	if (fi->inicio == NULL)
	{
		fi->inicio = novo;
		fi->fim = novo;
		// caso a pilha ja contenha algum elemento, o novo elemento será sempre inserido no fim da fila
	}
	else
	{
		fi->fim->prox = novo;
		fi->fim = novo;
	}
	printf("\nNumero inserido na fila!\n");
}

// os elementos da fila serão mostrados do primeiro inserido(inicio) ao último (fim)
void consulta_fila(Fila *fi)
{
	if (fi->inicio == NULL)
	{
		printf("\nFila Vazia!!");
	}
	else
	{
		aux = fi->inicio;
		do
		{
			printf(" %s \n", aux->nome);
			aux = aux->prox;
		} while (aux != NULL);
	}
}

// o elemento a ser removido será sempre o primeiro elemento inserido(inicio)
void remove_elemento_fila(Fila *fi)
{
	if (fi->inicio == NULL)
	{
		printf("\nFila Vazia!!");
	}
	else
	{
		aux = fi->inicio;
		printf("%d removido!", fi->inicio->nome);
		fi->inicio = fi->inicio->prox;
		free(aux);
	}
	getch();
}

// a fila será esvaziada e o espaço ocupado por ela será desalocado
void esvazia_fila(Fila *fi)
{
	if (fi->inicio == NULL)
	{
		printf("\nFila Vazia!!");
	}
	else
	{
		aux = fi->inicio;
		do
		{
			fi->inicio = fi->inicio->prox;
			free(aux);
			aux = fi->inicio;
		} while (aux != NULL);
		printf("\nFila Esvaziada!!");
	}
	getch();
}

int menu()
{
	int escolha_menu;

	printf("--------------------------------------------\n");
	printf("\tMenu\n\n");
	printf("--------------------------------------------\n");
	printf("1 - Abertura/Fechamento de conta\n");
	printf("2 - Emprestimo\n");
	printf("3 - Pagamentos\n");
	printf("Escolha seu servico: ");
	scanf("%d", &escolha_menu);
	printf("--------------------------------------------\n");
	switch (escolha_menu)
	{
	case 1:
		printf("1 Escolhido");
		return 1;
		break;
	case 2:
		printf("2 Escolhido");
		return 2;
		break;

	case 3:
		printf("programa encerrado");
		return 3;
		break;
	default:

		menu();
		printf("Erro ao escolher a opção");
		break;
	}
}

int main()
{
	Fila *fila_a = cria_fila();
	Fila *fila_b = cria_fila();
	Fila *fila_c = cria_fila();

	int escolha_menu_principal;
	do
	{
		char ficha[8] = "";

		escolha_menu_principal = menu();

		if (escolha_menu_principal == 1)
		{

			strcat(ficha, "CNTA");
			printf("%s", ficha);
			strcat(ficha, "003");
			insere_elemento(fila_a, ficha);
			consulta_fila(fila_a);
		}
		else if (escolha_menu_principal == 2)
		{

			ficha[8] = "CRED";
			strcat(ficha, "003");
			insere_elemento(fila_b, ficha);
			consulta_fila(fila_b);
		}
	} while (escolha_menu_principal != 3);

	return 0;
}
