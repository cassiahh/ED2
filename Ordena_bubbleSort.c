#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>




void Ordena_bubbleSort(int *v, int n){
	int i, continua, aux, fim = n;
	do{
		continua = 0;
		for(i = 0; i < fim - 1; i++){
			if(v[i] > v[i+1]){
				aux = v[i];
				v[i] = v[i+1];
				v[i+1] = aux;
				continua = i;
			}
		}
		fim--;
	}while(continua !=0);

}

int main () {

    int tamanho = {1000, 5000, 10000, 20000, 50000, 100000}, i;
    int *VET = (int*)malloc(tamanho * sizeof(int));

   srand(time(NULL));

   for ( i = 0; i <tamanho; i++ )
   {
      VET[i] = rand();
   }

    printf("\n\nVetor desordenado: \n\n");
    for(i = 0; i < tamanho; i++)
        printf("%d  ", VET[i]);

   Ordena_bubbleSort(VET, tamanho);

    printf("\n\nVetor ordenado: \n\n");
    for(i = 0; i < tamanho; i++)
        printf("%d  ", VET[i]);

    system("pause");


    return 0;
}
