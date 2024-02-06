#include <stdio.h>
#include <stdlib.h>

typedef struct elemento
{
    char operador;
    struct elemento *proximo;
} elemento;

typedef struct pilha
{
    elemento *topo;
} Pilha;

Pilha *inicializar()
{
    Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));
    pilha->topo = NULL;
    return pilha;
}

void push(Pilha *pilha, char operador)
{
    elemento *novo = (elemento *)malloc(sizeof(elemento));
    novo->operador = operador;
    novo->proximo = pilha->topo;
    pilha->topo = novo;
}

char pop(Pilha *pilha)
{
    if (pilha->topo == NULL)
    {
        printf("Erro: pilha vazia\n");
        exit(EXIT_FAILURE);
    }

    char operador = pilha->topo->operador;
    elemento *temp = pilha->topo;
    pilha->topo = pilha->topo->proximo;
    free(temp);

    return operador;
}

int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char c)
{
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    else
        return 0; // Assume que outros caracteres são operandos
}

int evaluateExpression(const char *expression)
{
    Pilha *operandStack = inicializar();
    Pilha *operatorStack = inicializar();

    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (expression[i] == ' ')
            continue; // Ignora espaços em branco

        if (isdigit(expression[i]))
        {
            int operand = 0;
            while (isdigit(expression[i]))
            {
                operand = operand * 10 + (expression[i] - '0');
                i++;
            }
            i--; // Para ajustar a posição do índice
            push(operandStack, operand);
        }

        else if (isOperator(expression[i]))
        {
            while (operatorStack->topo != NULL && operatorStack->topo->operador != '(' &&
                   precedence(operatorStack->topo->operador) >= precedence(expression[i]))
            {
                char op = pop(operatorStack);
                int operand2 = pop(operandStack);
                int operand1 = pop(operandStack);

                switch (op)
                {
                case '+':
                    push(operandStack, operand1 + operand2);
                    break;
                case '-':
                    push(operandStack, operand1 - operand2);
                    break;
                case '*':
                    push(operandStack, operand1 * operand2);
                    break;
                case '/':
                    push(operandStack, operand1 / operand2);
                    break;
                }
            }
            push(operatorStack, expression[i]);
        }
    }


    while (operatorStack->topo != NULL)
    {
        char op = pop(operatorStack);
        int operand2 = pop(operandStack);
        int operand1 = pop(operandStack);

        switch (op)
        {
        case '+':
            push(operandStack, operand1 + operand2);
            break;
        case '-':
            push(operandStack, operand1 - operand2);
            break;
        case '*':
            push(operandStack, operand1 * operand2);
            break;
        case '/':
            push(operandStack, operand1 / operand2);
            break;
        }
    }

    int result = pop(operandStack);

    free(operandStack);
    free(operatorStack);

    return result;
}

int percorrerPilha(Pilha *pilha)
{
    elemento *atual = pilha->topo;
    while (atual != NULL)
    {
        printf("%c\n", atual->operador);
        atual = atual->proximo;
    }
}

int main()
{
    // Testando a função de avaliação
    const char *expression1 = "3 + 5 * 2";
    const char *expression2 = "4 * (7 - 2)";
    const char *expression3 = "8 + 6 / 2 - 4";


    printf("Resultado 1: %d\n", evaluateExpression(expression1));
    printf("Resultado 2: %d\n", evaluateExpression(expression2));
    printf("Resultado 3: %d\n", evaluateExpression(expression3));

    return 0;
}
