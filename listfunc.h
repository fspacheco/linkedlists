/*Lista encadeada
* Fernando S. Pacheco
* 2015-03-16
* Baseado no material de Celes e Rangel Cap. 10
*
* Parte 1:
*  Inicialização, inserção, impressão, liberação
*/

#ifndef LISTFUNC_H
#define LISTFUNC_H

typedef struct _lista Lista;
struct _lista {
   int dado;
   Lista *prox;
};

Lista* inicializa(void);

Lista* insere(int dado, Lista* lst);

void imprime(Lista* lst);

void libera (Lista* lst);

#endif
