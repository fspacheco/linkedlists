/*!
* @file main.c
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
* Compilar com:
* gcc -Wall main.c listfunc.c -oevento
*
* Testar memória com:
* valgrind --tool=memcheck --leak-check=yes --show-reachable=yes ./evento
*
*/

#include "listfunc.h"
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
   Lista *ev = inicializa();
   Lista *b = NULL; 
   insere_ordenado("evento001", 20, 4, &ev);
   insere_ordenado("evento002", 20, 7, &ev);
   insere_ordenado("evento003", 12, 2, &ev);
   imprime(ev);
   b=busca_evento(20, 4, ev);
   if (b!=NULL) printf("Encontrado: %s\n", b->nome);

   if (remove_evento(20, 5, &ev) == 1) {
     printf("Elemento removido\n");
   }
   else {
     printf("Elemento não encontrado\n");
   }
   libera(ev);

   return EXIT_SUCCESS;
}
