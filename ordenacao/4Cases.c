#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int QtdOrd, k,tempo;
int main()
{
char Seleciona;
int menu_quantidade();

printf("Escolha o metodo de ordenacao");
printf("\n '1'-BubbleSort");
printf("\n '2'-InsertionSort");
printf("\n '3'-SelectionSort");
printf("\n '4'-ShellSort");
printf("\n '5'-MergeSort");
printf("\n '6'-QuickSort");
printf("\n '7'-HeapSort");
printf("\n '8'-RadixSort(LSD)\n");

printf("\nQual Metodo de Ordenacao Vamos Usar Hoje: ");
scanf("\n%c",&Seleciona);

int resultado;

switch (Seleciona)
{
case '1':
         printf("\nAeee, Legal! Vamos utilizar o BubbleSort\n");
         resultado = menu_quantidade();
         int BubbleSort(int TAM);
         BubbleSort(QtdOrd);
         break;

case '2':
         printf("\nAeee, Legal! Vamos utilizar o InsertionSort\n");
         resultado = menu_quantidade();
         int insertion(int TAM);
         insertion(QtdOrd);
         break;

case '3':
         printf("\nAeee, Legal! Vamos utilizar o SelectionSort\n");
         resultado = menu_quantidade();
         int SelectionSort(int TAM);
         SelectionSort(QtdOrd);
         break;

case '4':
         printf("\nAeee, Legal! Vamos utilizar o ShellSort\n");
         resultado = menu_quantidade();
         int ShellSort(int TAM);
         ShellSort(QtdOrd);
         break;
/*
case '5':
         printf("\nAeee, Legal! Vamos utilizar o MergeSort\n");
         resultado = menu_quantidade();
         int Aleatorio(int tamanho);
         Aleatorio(QtdOrd);
         break;

case '6':

         printf("\nAeee, Legal! Vamos utilizar o QuickSort\n");
         resultado = menu_quantidade();
         int Aleatorio(int tamanho);
         Aleatorio(QtdOrd);
         break;
case '7':

        printf("\nAeee, Legal! Vamos utilizar o HeapSort\n");
        resultado = menu_quantidade();
        int Aleatorio(int tamanho);
         Aleatorio(QtdOrd);
        break;
case '8':

        printf("\nAeee, Legal! Vamos utilizar o RadixSort\n");
        resultado = menu_quantidade();
        int Aleatorio(int tamanho);   //RadixSortLSD(VET, tamanho);
        Aleatorio(QtdOrd);
        break;
*/

default:
          printf("\nEi, voce digitou um valor correto?\n");
          return 0;
          break;
}
printf("\n\n");

  system("pause");
    return 0;

}

int menu_quantidade (){ // selecionar quantidade de elementos no vetor

printf("Agora escolha a quantidade de elementos a serem ordenados: ");
        printf("\n '1'-1.000");
        printf("\n '2'-5.000");
        printf("\n '3'-10.000");
        printf("\n '4'-20.000");
        printf("\n '5'-50.000");
        printf("\n '6'-100.000\n");
        scanf("%i",&QtdOrd);


        switch (QtdOrd){
            case 1: {
            QtdOrd = 1000;
            printf("\n %i",QtdOrd);
            return QtdOrd;
            }
            break;

            case 2:
            {
            QtdOrd = 5000;
            printf("\n \n %i",QtdOrd);
            return QtdOrd;
            }
            break;

            case 3:{
            QtdOrd = 10000;
            printf("\n \n %i",QtdOrd);
            return QtdOrd;
            }
            break;

            case 4:{
            QtdOrd = 20000;
            printf("\n \n %i",QtdOrd);
            return QtdOrd;
            }
            break;

            case 5:{
            QtdOrd = 50000;
            printf("\n \n %i",QtdOrd);
            return QtdOrd;
            }
            break;

            case 6:{
            QtdOrd = 100000;
            printf("\n \n %i",QtdOrd);
            return QtdOrd;
            }
            break;
            default:
            printf("\nEi, voce digitou um valor correto?\n");
            break;
        }
return 0;
}

int BubbleSort(int TAM)
{
   // Definição de variaveis usadas no programa
   int i, j, aux, trocas, tamanho = TAM;
   int vetor[TAM];

   // Preenchimento e escrita do vetor com numeros aleatorios
   srand(time(0));
   printf("\nVetor original\n");
   for(i=0;i<TAM;i++)
      { vetor[i]=rand()%1000;
      printf("Elemento %2d: %3d \n",i+1,vetor[i]);}

   // Inicializa a variavel trocas
   trocas = 0;

   // Ordenação do vetor na técnica BubbleSort
   for(i=0;i<=TAM;i++)
      {
      for(j=i+1;j<=TAM;j++)
         {
         if(vetor[j]<vetor[i])
            {
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            trocas++;
            }
         }
      }

   // Mostra vetor ordenado
   printf("\nVetor ordenado\n");
   for(i=0;i<tamanho;i++) printf("Elemento %2d: %3d \n",i+1,vetor[i]);
   printf("\n Foram Realizadas %d Trocas.\n", trocas);
    system("pause");
}

int insertion(int TAM)
{
   // Definição de variaveis usadas no programa
   int i, j, aux, trocas, tamanho = TAM;
   int vetor[TAM];

   // Preenchimento e escrita do vetor com numeros aleatorios
   srand(time(0));
   printf("\nVetor original\n");
   for(i=0;i<TAM;i++)
      { vetor[i]=rand()%1000;
      printf("Elemento %2d: %3d \n",i+1,vetor[i]);}

   // Inicializa a variavel trocas
   trocas = 0;

   // Ordenação do vetor na técnica InsertionSort

	for(i = 1; i < tamanho; i++){
		aux = vetor[i];
		for(j = i; (j > 0) && (aux < vetor[j-1]); j--){
			vetor[j] = vetor[j-1];
			trocas++;
		}
		vetor[j] = aux;
	}


   // Mostra vetor ordenado
   printf("\nVetor ordenado\n");
   for(i=0;i<tamanho;i++) printf("Elemento %2d: %3d \n",i+1,vetor[i]);
   printf("\n Foram Realizadas %d Trocas.\n", trocas);
    system("pause");
}

int SelectionSort(int TAM)
{
   // Definição de variaveis usadas no programa
   int i, j, aux, trocas, tamanho = TAM;
   int vetor[TAM];

   // Preenchimento e escrita do vetor com numeros aleatorios
   srand(time(0));
   printf("\nVetor original\n");
   for(i=0;i<TAM;i++)
      { vetor[i]=rand()%1000;
      printf("Elemento %2d: %3d \n",i+1,vetor[i]);}

   // Inicializa a variavel trocas
   trocas = 0;

   // Ordenação do vetor na técnica InsertionSort


    int  menor;
	for(i = 0; i < tamanho - 1; i++){
		menor = i;
		for(j = i + 1; j < tamanho; j++) {
			if (vetor[j] < vetor[menor]){
				menor = j;
				trocas++;
			}
		}
		if(i != menor){
			aux = vetor[i];
			vetor[i] = vetor[menor];
			vetor[menor] = aux;
			trocas++;
		}
	}


   // Mostra vetor ordenado
   printf("\nVetor ordenado\n");
   for(i=0;i<tamanho;i++) printf("Elemento %2d: %3d \n",i+1,vetor[i]);
   printf("\n Foram Realizadas %d Trocas.\n", trocas);
    system("pause");
}

int ShellSort(int TAM)
{
   // Definição de variaveis usadas no programa
   int i, j, aux, trocas, tamanho = TAM,x;
   int vetor[TAM];

   // Preenchimento e escrita do vetor com numeros aleatorios
   srand(time(0));
   printf("\nVetor original\n");
   for(i=0;i<TAM;i++)
      { vetor[i]=rand()%1000;
      printf("Elemento %2d: %3d \n",i+1,vetor[i]);}

   // Inicializa a variavel trocas
   trocas = 0;

   // Ordenação do vetor na técnica ShellSort


	for(k = 0; k < tamanho; k++){
		aux = vetor[k];
		for(i = aux; i < tamanho; i++){
			x = vetor[i];
			for(j = i - aux; x < vetor[j] && j >= 0; j = j - aux){
				vetor[j + aux] = vetor[j];
                    trocas++;
			}
			vetor[j + aux] = x;
            trocas++;
		}
	}

   // Mostra vetor ordenado
   printf("\nVetor ordenado\n");
   for(i=0;i<tamanho;i++) printf("Elemento %2d: %3d \n",i+1,vetor[i]);
   printf("\n Foram Realizadas %d Trocas.\n", trocas);
    system("pause");
}





void RadixSortLSD(int *vetor, int tamanho)
{
    int i;
    int *b;
    int maior = vetor[0];
    int exp = 1;

    b = (int *)calloc(tamanho, sizeof(int));

    for (i = 0; i < tamanho; i++) {
        if (vetor[i] > maior)
    	    maior = vetor[i];
    }

    while (maior/exp > 0) {
        int bucket[10] = { 0 };
    	for (i = 0; i < tamanho; i++)
    	    bucket[(vetor[i] / exp) % 10]++;
    	for (i = 1; i < 10; i++)
    	    bucket[i] += bucket[i - 1];
    	for (i = tamanho - 1; i >= 0; i--)
    	    b[--bucket[(vetor[i] / exp) % 10]] = vetor[i];
    	for (i = 0; i < tamanho; i++)
    	    vetor[i] = b[i];
    	exp *= 10;
    }

    free(b);
}

