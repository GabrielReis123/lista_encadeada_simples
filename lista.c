#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void FLVazia(TipoLista *Lista) {
    Lista->Primeiro = (TipoApontador) malloc(sizeof(TipoCelula));
    Lista->Ultimo   = Lista->Primeiro;
    Lista->Primeiro->Prox = NULL;
}

int Vazia(TipoLista Lista) {
    return (Lista.Primeiro == Lista.Ultimo);
}

void Insere(TipoItem x, TipoLista *Lista) {
    Lista->Ultimo->Prox = (TipoApontador) malloc(sizeof(TipoCelula));
    Lista->Ultimo       = Lista->Ultimo->Prox;
    Lista->Ultimo->Item = x;
    Lista->Ultimo->Prox = NULL;
}

void Retira(TipoApontador p, TipoLista *Lista, TipoItem *Item) {
    TipoApontador q;
    if (Vazia(*Lista) || p == NULL || p->Prox == NULL) {
        printf("Erro: lista vazia ou posicao invalida\n");
        return;
    }
    q        = p->Prox;
    *Item    = q->Item;
    p->Prox  = q->Prox;
    if (p->Prox == NULL) Lista->Ultimo = p;
    free(q);
}

void Imprime(TipoLista Lista) {
    TipoApontador Aux = Lista.Primeiro->Prox;
    while (Aux != NULL) {
        printf("%d\n", Aux->Item.Chave);
        Aux = Aux->Prox;
    }
}

void RetiraUltimo(TipoLista *Lista, TipoItem *Item) {
    /* IMPLEMENTAR */
    TipoApontador penultimo = Lista->Primeiro;
    while(penultimo->Prox != Lista->Ultimo){
        penultimo = penultimo->Prox;

    }
    penultimo->Prox = NULL;
    *Item = Lista->Ultimo->Item;
    free(Lista->Ultimo);
    
    Lista->Ultimo = penultimo;

}

void InsereInicio(TipoItem x, TipoLista *Lista) {
    /* IMPLEMENTAR */
    TipoApontador novo = (TipoApontador)malloc(sizeof(TipoCelula));
    novo->Item = x;
    novo->Prox = Lista->Primeiro->Prox;
    Lista->Primeiro->Prox = novo; //Diz que o próximo elemento depois do primeiro é o 'novo'
    if(Lista->Ultimo == Lista->Primeiro){
        Lista->Ultimo = novo;

    }

}

void Inverte(TipoLista *Lista) {
    /* IMPLEMENTAR */
    if(Vazia(*Lista) || Lista->Primeiro->Prox->Prox == NULL) return;
    TipoApontador anterior = NULL;
    TipoApontador atual = Lista->Primeiro->Prox;
    TipoApontador proximo = NULL;

    Lista->Ultimo = atual;
    while(atual != NULL){
        proximo = atual->Prox;
        atual->Prox = anterior;
        anterior = atual;
        atual = proximo;

    }
    Lista->Primeiro->Prox = anterior;
    
}

int Tamanho(TipoLista *Lista) {
    /* IMPLEMENTAR */
    TipoApontador aux;
    aux = Lista->Primeiro->Prox;

    int tam =0;

    while(aux!= NULL){
        tam++;
        aux = aux->Prox;

    }
    return tam;

}
