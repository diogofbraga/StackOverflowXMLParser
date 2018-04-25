#include <stdio.h>
#include "list.h"
#include "tcd.h"
#include "funcoes.h"
#include "query6.h"

// query 6

LONG_list most_voted_answers(TAD_community com, int N, Date begin, Date end){ // da com mais respostas para a q tem menos

  LONG_list res = create_list(N);

  for (int i=0; i < N ; i++){ // inicialização da lista
    set_list(res,i,0); // lista q vai ser devolvida
  }

  GList* gl = get_date_posts(com);
  GList* glista = gl;
  GList* glvotes = NULL;

  while(glista != NULL){
    if(get_post_type_id(glista->data) == 2){ // se é resposta
      
      if(difDatas(get_data(glista->data),begin,end) == 0){ // se está dentro das datas
        // insere no inicio as respostas
        glvotes = g_list_insert(glvotes, (gpointer) glista->data, 0);

      }
    }
    glista = glista->next;
  }

  // ordena a lista por ordem crescente
  glvotes = g_list_sort(glvotes, compara_score);

  int i = 0;
  while(glvotes != NULL && i < N){
      set_list(res,i,get_key_id_post(glvotes->data));
      glvotes = g_list_next(glvotes);
      i++;
  }

  LONG_list aux = remove_trash(res, N);
  
  // para testar
  for(int i = 0; i < N; i++){
    if( (void*) get_list(aux,i) == NULL) break;
    printf("POST_ID: %ld\n", get_list(aux,i) );
  }

  return aux;
}