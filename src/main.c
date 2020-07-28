#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.>

#define NUMS 32
#define WORKERS 4

pthread_mutex_t trava;
unsigned int vetor[NUMS], num_primos = 0, size_vet = 0;

void input_vetor(){
   int l;
   char u;

   for ( l = 0 ; l < NUMS ; l++ ) {
      u = scanf("%u", %vetor[l]);

      if( u == EOF ){
         size_vet = l;
         break;
      }
   }
}

void* worker(void arg*){
   
   
   do {
      pthread_mutex_lock(&trava);


      pthread_mutex_unlock(&trava);
   } while(num_primos <= NUMS);

   return NULL;
}


unsigned long int verifica_primo(int number){

  int cont_div = 0, n_primos = 0;

  for(int j = 1; j <= number ; j++){
  /* Se é divisor e o numero é != 1, +1 divisor encontrado */
     if ((number % j == 0) && (j != 1)) cont_div++;

  /* Se encontrar 2 divisor, quebrar laço */
     if (cont_div > 1) break;
  }
 
  /* Se só houver 1 divisor, foi encontrado um número primo */
  if (cont_div == 1) n_primos++;

  return n_primos;
}


int main() {

  pthread_t workers[WORKERS];
  int thread_id[WORKERS];

  /* Lendo vetor de números */
  input_vetor();

  /* Identificadores de thread */
  for (int i=0; i<WORKERS; i++) {
    thread_id[i] = i;
  }

  /* Iniciando Threads */
  for (int i=0; i<WORKERS; i++) {
    pthread_create(&(workers[i]), NULL, worker, (void*) (&thread_id[i]));
  }

  /* Esperando threads */
  for (int i=0; i<WORKERS; i++) pthread_join(workers[i], NULL);

  return 0;
}
