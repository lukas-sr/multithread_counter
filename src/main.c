/* Contador de palavras
 *
 * Este programa recebera uma serie de caracteres representando palavras em sua
 * entrada. Ao receber um caractere fim de linha ('\n'), deve imprimir na tela o
 * numero de palavras separadas que recebeu e, apos, encerrar.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.>

#define NUMS 64
#define WORKS 4

void* worker(void *arg){
	int *N = (int*) (arg);

}
int main() {

  int x, y;

  scanf("%d %d\n", &x, &y);
  printf("%d\n", x + 200);
  return 0;
}
