/*Lista encadeada
* Fernando S. Pacheco
* 2015-03-16
* Baseado no material de Celes e Rangel Cap. 10
*
* Parte 1:
*  Inicialização, inserção, impressão, liberação
*/

#include "listfunc.h"
#include <stdio.h>
#include <stdlib.h>

Lista* inicializa(void) {
   return NULL;
}

Lista* insere(int dado, Lista* lst) {
   Lista* novo = (Lista*) malloc(sizeof(Lista));
   if (novo==NULL) exit(EXIT_FAILURE);
   novo->dado = dado;
   novo->prox = lst;
   return novo;
}

void imprime(Lista* lst) {
   Lista *p;
   int k=0;
   printf("n\tend\t\tdado\tprox\n");
   for (p=lst; p!=NULL; p=p->prox) {
      printf("%d\t%p\t%d\t%p\n", k, p, p->dado, p->prox);
      k++;
   }
   printf("----------------------------------------------\n");
}

void libera (Lista* lst) {
   Lista* p = lst;
   while (p != NULL) {
      Lista* t=p->prox; /* guarda referência para o próximo elemento*/
      free(p); /* libera a memória apontada por p */
      p = t; /* faz p apontar para o próximo */
   }
}

