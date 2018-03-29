#ifndef __QUERY8__
#define __QUERY8__

/**
@file query8.h
@author Grupo21
@brief Ficheiro que contém as funções da query 8.
*/


/**
@brief Função que dado uma palavra devolve uma lista com os IDs de N perguntas cujos títulos a contenham, 
ordenados por cronologia inversa.

@param com Estrutura com os dados.
@param word Parâmetro de comparação.
@param N Número de perguntas pedidas.

@returns Lista com os IDs.
*/
LONG_list contains_word(TAD_community com, char* word, int N);

#endif