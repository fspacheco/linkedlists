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


int main(void)
{
   Lista* lst = inicializa();
   printf("##%p##\n",&lst);
   imprime(lst);
   lst=insere(100, lst);
   lst=insere(97, lst);
   imprime(lst);
   libera(lst);
   lst=NULL;
   imprime(lst);

   return EXIT_SUCCESS;
}
