// Biblioteca de entrada e saida de dados (I/O)
#include <stdio.h>
// Biblioteca com a função MALLOC
#include <stdlib.h>

/* Um struct seria como uma classe. Classe esta que possui abributos, no nosso caso, os atributos são uma struct do item anterior da nossa lista, um dado do tipo int e uma struct do proximo elemento */
struct No {
    int info;    
	struct No *anterior;
    struct No *proximo;
};

/* Criamos duas struct, a da cabeça(quem vai receber o endereco de memória do primeiro elemento) e o último (que vai receber os dados do último elemento. Ambos começam NULOS, para depois receberem as informações)*/
struct No *cabeca = NULL;
struct No *ultimo = NULL;

// Criamos a função que cria os nós da nossa lista encadeada

void adicionaLista(int elemento) {
    // Criamos um novo struct chamado NO e o procuramos um endereço de memória livre com a função MALLOC
    struct No *novo = (struct No*)malloc(sizeof(struct No));
	// Para atribuir um endereço de memória no ANTERIOR, vamos, através da condicional, saber se a cabeça da nossa lista está vazia (NULL), caso sim, o valor de ANTERIOR será o endereço de memória da cabeça, senão, será o endereço de memória do último   
    if(cabeca == NULL) {
    	novo -> anterior = cabeca;
	} else {
		novo -> anterior = ultimo;
	}
	// Assim que o MALLOC encontra um endereço de memória livre para alocar nossa struct NOVO, agora armazenamos dentro dele os atributos que queremos(o elemento e o endereço do próximo NO da LISTA)
	novo -> info = elemento;
    novo -> proximo = NULL;
    // Através do condicional, iremos perguntar se a estrutura cabeça está livre (NULL). Caso sim, ela receberá o valor do NOVO e o último também receberá o mesmo valor
    if(cabeca == NULL) {
        cabeca = novo;
        ultimo = novo;
    // Caso a cabeça da nossa lista não seja nula, será somente o ÚLTIMO quem receberá os valores de NOVO, sendo o atributo próximo com o valor de memória do novo e os dados de novo.
    } else {
        ultimo -> proximo = novo;
        ultimo = novo;
    }
}

// Agora, criaremos a função para imprimir nossa Lista Dinamica Simplesmente Encadeada

void imprimeLista() {
    // Como os valores estão armazenados e espalhados na memória, iremos criar um auxiliar que irá acessar e imprimir todos os valores em tela conforme for os acessando
    // Neste primeiro momento, o auxiliar receberá o valor da cabeça da lista, para assim saber o proximo valor e assim por diante
    struct No *auxiliar = cabeca;
    // Criamos um laço WHILE para quem, enquanto o endereço armazemnado em PRÓXIMO for diferente de NULL, ele imprimir os dados daquele nó.
    // Após imprimir, o AUXILIAR receberá o endereço de memória do próximo auxiliar, para assim acessar os dados do próximo NO
    while(auxiliar != NULL) {
        printf("\n%x, %i, %x", auxiliar, auxiliar -> info, auxiliar -> proximo);
    	auxiliar = auxiliar -> proximo;
	}

}

// Agora, criaremos a função para imprimirReverso para testar os endereços de memória do nosso atributo anterior em nossa Lista Dinamica Duplamente Encadeada

void imprimeListaReversa() {
    // Como os valores estão armazenados e espalhados na memória, iremos criar um auxiliar que irá acessar e imprimir todos os valores em tela conforme for os acessando
    // Neste primeiro momento, o auxiliar receberá o valor do último da lista, para assim saber valor anterior e assim por diante
    struct No *auxiliar = ultimo;
    // Criamos um laço WHILE para quem, enquanto o endereço armazemnado em ANTERIOR for diferente de NULL, ele imprimir os dados daquele nó.
    // Após imprimir, o AUXILIAR receberá o endereço de memória anterior do auxiliar, para assim acessar os dados do NO anterior
    while(auxiliar != NULL) {
        printf("\n%x <- %x, %i", auxiliar -> anterior, auxiliar, auxiliar -> info);
    	auxiliar = auxiliar -> anterior;
	}

}

// Para saber quantos elementos têm a nossa Lista, vamos criar a função tamanhoLista(), para contar a quantidade de nós da mesma
void tamanhoLista() {
	int soma = 0;
	struct No *auxiliar = cabeca;
	while(auxiliar != NULL) {
		soma++;
		auxiliar = auxiliar -> proximo;
	}
	printf("\n\nNossa Lista encadeada tem %i nos", soma);
}

// Vamos criar um executável (MAIN) para testar a função. Testaremos com 5 valores, de 1 a 5

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

