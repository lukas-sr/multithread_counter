#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define NUMS 32
#define WORKERS 4

pthread_mutex_t key;
unsigned int vetor[NUMS], num_primos = 0, size_vet = 0;

void input_vetor(){
   int l;
   char u;

   for ( l = 0 ; l < NUMS ; l++ ) {
      u = scanf("%u", &vetor[l]);

      if( u == EOF ){
         size_vet = l;
         break;
      }
   }
}


int verifica_primo(unsigned long int number){

  int cont_div = 0, primos = 0;

  for(unsigned int j = 2; (j <= number) && (number>=2) ; j++){
  /* Se é divisor e o numero é != 1, +1 divisor encontrado */
     if ((number % j) == 0) cont_div++;

  /* Se encontrar 2 divisor, quebrar laço */
     if (cont_div > 1) break;
  }
 
  /* Se só houver 1 divisor, foi encontrado um número primo */
  if (cont_div == 1) primos++;

  return primos;
  
}

void* worker(void *arg){
   int *N = (int*)(arg);
   int M = (*N);

   for(unsigned int i = M; i < size_vet ; i+=WORKERS) {
      pthread_mutex_lock(&key);
      num_primos += verifica_primo(vetor[i]); 
      pthread_mutex_unlock(&key);
   }
   return NULL;
}

int main() {
  pthread_t workers[WORKERS];
  int thread_id[WORKERS];

  /* Lendo vetor de números */
  input_vetor();

  /* Identificadores de thread */
  for (int i=0; i<WORKERS; i++) thread_id[i] = i;

  /* Iniciando Threads */
  for (int i=0; i<WORKERS; i++) pthread_create(&(workers[i]), NULL, worker, (void*) (&thread_id[i]));

  /* Esperando threads */
  for (int i=0; i<WORKERS; i++) pthread_join(workers[i], NULL);

  printf("%d\n", num_primos);

  return 0;
}
