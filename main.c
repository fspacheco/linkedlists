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
*/

#include "listfunc.h"
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
   Lista* lst = inicializa();
   printf("##%p##\n",&lst);
   imprime(lst);
   insere(100, &lst);
   insere(97, &lst);
   imprime(lst);
   libera(lst);
   lst=NULL;
   imprime(lst);

   return EXIT_SUCCESS;
}
