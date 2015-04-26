/*!
* @file listfunc.h
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
*/

#ifndef LISTFUNC_H
#define LISTFUNC_H


typedef struct _lista Lista;
typedef struct _data Data;
struct _data {
   int dia;
   int mes;
};

/*!
* @brief Estrutura que define um nó da lista
*/
struct _lista {
   char* nome;
   Data data;
   Lista *prox;
};

/*! @brief Inicialização
*/
Lista* inicializa(void);

/*! @brief Inserção de elemento na lista, usando ponteiro para ponteiro como parâmetro
*/
void insere(char* nome, int dia, int mes, Lista** ev);

/*! @brief Impressão de todos os elementos
*/
void imprime(Lista* ev);

/*! @brief Desaloca todos os elementos da lista
*/
void libera(Lista* ev);

/*! @brief Busca um elemento da lista a partir de uma entrada
*/
Lista* busca_evento(int dia, int mes, Lista* ev);

/*! @brief Remove um elemento da lista a partir de uma entrada. Retorna 1 se sucesso e -1 se não encontrado
*/
int remove_evento(int dia, int mes, Lista** ev);

/*! @brief Insere elemento em ordem
*/
void insere_ordenado(char* nome, int dia, int mes, Lista** ev);

#endif
