/*!
* @file main.c
* @author Fernando S. Pacheco
* @date 2015-03-16
* @brief Lista encadeada - Baseado no material de Celes e Rangel Cap. 10
*
* Parte 1:
*  Inicialização, inserção, impressão, liberação
* Parte 2:
*  Usando ponteiro para ponteiro (insere2)
* Parte 3:
*  Funções de busca e remoção
*/

#include "listfunc.h"
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
   Lista *lst = inicializa();
   Lista *b = NULL; 
   printf("##%p##\n",&lst);
   imprime(lst);
   insere(100, &lst);
   insere(97, &lst);
   insere(42, &lst);
   imprime(lst);
   b=busca(lst, 97);
   if (b!=NULL) printf("Encontrado: %d\n", b->dado);
   if (apaga(&lst, 97)) {
     printf("Elemento removido\n");
   }
   else {
     printf("Elemento não encontrado\n");
   } 
   libera(lst);
   lst=NULL;
   imprime(lst);

   return EXIT_SUCCESS;
}
