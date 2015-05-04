/*!
* @file listfunc.c
* @author Fernando S. Pacheco
* @date 2015-03-16
* @brief Lista encadeada - Baseado no material de Celes e Rangel Cap. 10
*
1. Crie uma lista encadeada que armazene informações sobre eventos, com os seguintes campos:
nome, um vetor de caracteres;
data, que é uma estrutura com os campos dia e mês (inteiros). Considere que todos os eventos ocorrem no mesmo ano e que não há eventos repetidos.
Você deve criar, no mínimo, as seguintes funções:
 void insere(char* nome, int dia, int mes, Lista** ev);
 void imprime(Lista* ev);
 Lista* busca_evento(int dia, int mes, Lista* ev); (função retorna ponteiro para nó ou NULL se não encontrar)
 int remove_evento(int dia, int mes, Lista** ev); (função retorna 1 para sucesso e -1 caso contrário)
 void libera(Lista* ev); (função apaga a lista inteira de eventos)
 void insere_ordenado(char* nome, int dia, int mes, Lista** ev); (em ordem cronológica crescente)

Desenvolva, também, uma função main() que teste as funções criadas.
*
*/

#include "listfunc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Lista* inicializa(void) {
   return NULL;
}

void insere(char* nome, int dia, int mes, Lista** ev) {
   Lista* novo = (Lista*) malloc(sizeof(Lista));
   if (novo==NULL) {
     exit(EXIT_FAILURE);
   }
   char* nptr = (char*) malloc(strlen(nome)+1);
   if (nptr==NULL) exit(EXIT_FAILURE);
   //printf("##debug: %p\n", nptr);
   strcpy(nptr, nome);
   novo->nome = nptr;
   novo->data.dia = dia;
   novo->data.mes = mes;
   novo->prox = *ev;
   *ev=novo;   
}

void imprime(Lista* ev) {
   Lista *p;
   int k=0;
   printf("n\tend\t\tdia/mes\tnome\t\tprox\n");
   for (p=ev; p!=NULL; p=p->prox) {
      printf("%d\t%p\t%d/%d\t%s\t\t%p\n", k, p, p->data.dia, p->data.mes, p->nome, p->prox);
      k++;
   }
   printf("----------------------------------------------\n");
}


void libera(Lista* ev) {
   Lista* p = ev;
   while (p != NULL) {
      Lista* t=p->prox; //guarda referência para o próximo elemento//
      char* nptr=p->nome;
      //printf("##debug: %p\n", p->nome);
      free(nptr);
      free(p); // libera a memória apontada por p //
      p = t; // faz p apontar para o próximo //
   }
}

Lista* busca_evento(int dia, int mes, Lista* ev) {
  Lista* p;
  for (p=ev; p!=NULL; p=p->prox) {
    if (p->data.dia == dia && p->data.mes == mes) {
      return p;
    }
  }
  return NULL; // se não achou o elemento, retorna nulo //
}

int remove_evento(int dia, int mes, Lista** ev) {
  Lista* ant = NULL; //ponteiro para elemento anterior //
  Lista* p = *ev;//ponteiro para percorrer a lista//

  // procura elemento na lista, guardando anterior //
  while (p != NULL) {
    if  (p->data.dia == dia && p->data.mes == mes) {
      break; //encontrou
    }
    ant = p;
    p = p->prox;
  }
  // verifica se achou elemento //
  if (p == NULL)
    return -1; // não achou: retorna -1 //

  // retira elemento //
  if (ant == NULL) {
  // retira elemento do inicio //
    *ev = p->prox;
  }
  else {
    // retira elemento do meio da lista //
    ant->prox = p->prox;
  }
  free(p->nome);
  free(p);
  return 1;//sucesso//
}

// função auxiliar: cria e inicializa um nó //
Lista* cria (char* nome, int dia, int mes) {
  Lista* novo = (Lista*) malloc(sizeof(Lista));
  if (novo==NULL) {
    exit(EXIT_FAILURE);
  }
  novo->data.dia = dia;
  novo->data.mes = mes;
  char* nptr = (char*) malloc(strlen(nome)+1);
  if (nptr==NULL) exit(EXIT_FAILURE);
  strcpy(nptr, nome);
  novo->nome = nptr;
  return novo;
}

// função insere_ordenado: insere elemento em ordem //
void insere_ordenado(char* nome, int dia, int mes, Lista** ev) {
  Lista* novo = cria(nome, dia, mes); // cria novo nó //
  Lista* ant = NULL; // ponteiro para elemento anterior //
  Lista* p = *ev;  // ponteiro para percorrer a lista//
  // procura posição de inserção //
  while (p != NULL) {
    if (p->data.mes < mes) { //se o mês é menor, não precisa nem verificar o dia
      break;
    }
    if (p->data.mes == mes && p->data.dia < dia) { //se estiver no mesmo mês, aí sim precisa conferir o dia
        break;
    }
    ant = p;
    p = p->prox;
  }
  // insere elemento //
  if (ant == NULL) {
  // insere elemento no início //
    novo->prox = *ev;
    *ev = novo;
  }
  else {
    // insere elemento no meio da lista //
    novo->prox = ant->prox;
    ant->prox = novo;
  }
}



