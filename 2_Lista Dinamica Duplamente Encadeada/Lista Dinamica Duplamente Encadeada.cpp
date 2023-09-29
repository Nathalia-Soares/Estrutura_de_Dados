// Biblioteca de entrada e saida de dados (I/O)
#include <stdio.h>
// Biblioteca com a fun��o MALLOC
#include <stdlib.h>

/* Um struct seria como uma classe. Classe esta que possui abributos, no nosso caso, os atributos s�o uma struct do item anterior da nossa lista, um dado do tipo int e uma struct do proximo elemento */
struct No {
    int info;    
	struct No *anterior;
    struct No *proximo;
};

/* Criamos duas struct, a da cabe�a(quem vai receber o endereco de mem�ria do primeiro elemento) e o �ltimo (que vai receber os dados do �ltimo elemento. Ambos come�am NULOS, para depois receberem as informa��es)*/
struct No *cabeca = NULL;
struct No *ultimo = NULL;

// Criamos a fun��o que cria os n�s da nossa lista encadeada

void adicionaLista(int elemento) {
    // Criamos um novo struct chamado NO e o procuramos um endere�o de mem�ria livre com a fun��o MALLOC
    struct No *novo = (struct No*)malloc(sizeof(struct No));
	// Para atribuir um endere�o de mem�ria no ANTERIOR, vamos, atrav�s da condicional, saber se a cabe�a da nossa lista est� vazia (NULL), caso sim, o valor de ANTERIOR ser� o endere�o de mem�ria da cabe�a, sen�o, ser� o endere�o de mem�ria do �ltimo   
    if(cabeca == NULL) {
    	novo -> anterior = cabeca;
	} else {
		novo -> anterior = ultimo;
	}
	// Assim que o MALLOC encontra um endere�o de mem�ria livre para alocar nossa struct NOVO, agora armazenamos dentro dele os atributos que queremos(o elemento e o endere�o do pr�ximo NO da LISTA)
	novo -> info = elemento;
    novo -> proximo = NULL;
    // Atrav�s do condicional, iremos perguntar se a estrutura cabe�a est� livre (NULL). Caso sim, ela receber� o valor do NOVO e o �ltimo tamb�m receber� o mesmo valor
    if(cabeca == NULL) {
        cabeca = novo;
        ultimo = novo;
    // Caso a cabe�a da nossa lista n�o seja nula, ser� somente o �LTIMO quem receber� os valores de NOVO, sendo o atributo pr�ximo com o valor de mem�ria do novo e os dados de novo.
    } else {
        ultimo -> proximo = novo;
        ultimo = novo;
    }
}

// Agora, criaremos a fun��o para imprimir nossa Lista Dinamica Simplesmente Encadeada

void imprimeLista() {
    // Como os valores est�o armazenados e espalhados na mem�ria, iremos criar um auxiliar que ir� acessar e imprimir todos os valores em tela conforme for os acessando
    // Neste primeiro momento, o auxiliar receber� o valor da cabe�a da lista, para assim saber o proximo valor e assim por diante
    struct No *auxiliar = cabeca;
    // Criamos um la�o WHILE para quem, enquanto o endere�o armazemnado em PR�XIMO for diferente de NULL, ele imprimir os dados daquele n�.
    // Ap�s imprimir, o AUXILIAR receber� o endere�o de mem�ria do pr�ximo auxiliar, para assim acessar os dados do pr�ximo NO
    while(auxiliar != NULL) {
        printf("\n%x, %i, %x", auxiliar, auxiliar -> info, auxiliar -> proximo);
    	auxiliar = auxiliar -> proximo;
	}

}

// Agora, criaremos a fun��o para imprimirReverso para testar os endere�os de mem�ria do nosso atributo anterior em nossa Lista Dinamica Duplamente Encadeada

void imprimeListaReversa() {
    // Como os valores est�o armazenados e espalhados na mem�ria, iremos criar um auxiliar que ir� acessar e imprimir todos os valores em tela conforme for os acessando
    // Neste primeiro momento, o auxiliar receber� o valor do �ltimo da lista, para assim saber valor anterior e assim por diante
    struct No *auxiliar = ultimo;
    // Criamos um la�o WHILE para quem, enquanto o endere�o armazemnado em ANTERIOR for diferente de NULL, ele imprimir os dados daquele n�.
    // Ap�s imprimir, o AUXILIAR receber� o endere�o de mem�ria anterior do auxiliar, para assim acessar os dados do NO anterior
    while(auxiliar != NULL) {
        printf("\n%x <- %x, %i", auxiliar -> anterior, auxiliar, auxiliar -> info);
    	auxiliar = auxiliar -> anterior;
	}

}

// Para saber quantos elementos t�m a nossa Lista, vamos criar a fun��o tamanhoLista(), para contar a quantidade de n�s da mesma
void tamanhoLista() {
	int soma = 0;
	struct No *auxiliar = cabeca;
	while(auxiliar != NULL) {
		soma++;
		auxiliar = auxiliar -> proximo;
	}
	printf("\n\nNossa Lista encadeada tem %i nos", soma);
}

// Vamos criar um execut�vel (MAIN) para testar a fun��o. Testaremos com 5 valores, de 1 a 5

main() {
    adicionaLista(1);
    adicionaLista(2);
    adicionaLista(3);
    adicionaLista(4);
    adicionaLista(5);
    printf("\n === Lista ===\n");
    printf("\n *mem // info // *prox\n");
    imprimeLista();
    printf("\n === Lista Reversa ===\n");
    printf("\n *ant // *mem // info //\n");
    imprimeListaReversa();
    printf("\n\n === Tamanho da Lista ===\n");
    tamanhoLista();
}

