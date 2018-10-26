#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int VET, tamanho, i;

int menu_metodo(){

char Seleciona;

printf("\nEscolha o metodo de ordenacao");
printf("\n '1'-BubbleSort");
printf("\n '2'-InsertionSort");
printf("\n '3'-SelectionSort");
printf("\n '4'-ShellSort");
printf("\n '5'-MergeSort");
printf("\n '6'-QuickSort");
printf("\n '7'-HeapSort");
printf("\n '8'-RadixSort(LSD)\n");

printf("\nEscolha um Metodo de Ordenacao: ");
scanf("\n%c",&Seleciona);

switch (Seleciona){
case '1':{
        printf("\nAeee, Legal! Vamos utilizar o BubbleSort\n");
        Ordena_bubbleSort(VET, tamanho);
        break;
        }
case '2':
         {
        printf("\nAeee, Legal! Vamos utilizar o InsertionSort\n");
        Ordena_insertionSort(VET, tamanho);
        }
case '3':{
        printf("\nAeee, Legal! Vamos utilizar o SelectionSort\n");
        Ordena_selectionSort(VET, tamanho);
        break;
        }
case '4': {
        printf("\nAeee, Legal! Vamos utilizar o ShellSort\n");
        Ordena_shellSort(VET, tamanho);
        break;
       }
case '5':{
         printf("\nAeee, Legal! Vamos utilizar o MergeSort\n");

        break;
        }
case '6':{
        printf("\nAeee, Legal! Vamos utilizar o QuickSort\n");

        break;
        }
case '7':{
        printf("\nAeee, Legal! Vamos utilizar o HeapSort\n");
        HeapSort(VET, tamanho);
        break;
        }
case '8':{
        printf("\nAeee, Legal! Vamos utilizar o RadixSort LSD\n");
        RadixSortLSD(VET, tamanho);
        break;
        }
printf("\n\n");
    }

}

int menu_quantidade (){ // selecionar quantidade de elementos no vetor

int QtdOrd;

printf("\nEscolha a quantidade de elementos a serem ordenados");
        printf("\n '1'-1.000");
        printf("\n '2'-5.000");
        printf("\n '3'-10.000");
        printf("\n '4'-20.000");
        printf("\n '5'-50.000");
        printf("\n '6'-100.000\n");
        printf("\nEscolha a quantidade de elementos a serem ordenados: ");
        scanf("%i",&QtdOrd);


        switch (QtdOrd){
            case 1: {printf("\n 1.000");
            vetor(1000);
            }
            break;
            case 2:{printf("\n 5.000");
            vetor(5000);
            }
            break;
            case 3:{printf("\n 10.000");
            vetor(10000);
            }
            break;
            case 4:{printf("\n 20.000");
            vetor(20000);
            }
            break;
            case 5:{printf("\n 50.000");
            vetor(50000);
            }
            break;
            case 6:{printf("\n 100.000");
            vetor(100000);
            }
            break;
return 0;
}

}

int vetor(QtdOrd){//Cria os Valores aleatorios para ordenar

//  int tamanho = {1000, 5000, 10000, 20000, 50000, 100000}, i;
    int *VET = (int*)malloc(QtdOrd * sizeof(int));//alocação de memória
       srand(time(NULL));
           for ( i = 0; i <tamanho; i++ ){
                VET[i] = rand();
                }
}


double tempo(){
 struct timeval tv;
 gettimeofday(&tv,0);
 return tv.tv_sec + tv.tv_usec/1e6;
}



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

void Ordena_selectionSort(int *v, int n){
	int i, j, menor, troca;
	for(i = 0; i < n - 1; i++){
		menor = i;
		for(j = i + 1; j < n; j++) {
			if (v[j] < v[menor]){
				menor = j;
			}
		}
		if(i != menor){
			troca = v[i];
			v[i] = v[menor];
			v[menor] = troca;
		}
	}
}

void Ordena_insertionSort(int *v, int n){
	int i, j, aux;
	for(i = 1; i < n; i++){
		aux = v[i];
		for(j = i; (j > 0) && (aux < v[j-1]); j--){
			v[j] = v[j-1];
		}
		v[j] = aux;
	}
}

void Ordena_shellSort(int *v, int n){
	int i, j, gap, k;
	int x, a[5] = {9, 5, 3, 2, 1};

	for(k = 0; k < 5; k++){
		gap = a[k];
		for(i = gap; i < n; i++){
			x = v[i];
			for(j = i - gap; x < v[j] && j >= 0; j = j - gap){
				v[j + gap] = v[j];
			}
			v[j + gap] = x;
		}
	}
}

void mergeSort(int vetor[], int comeco, int fim){
    if (comeco < fim) {
        int meio = (fim+comeco)/2;

        mergeSort(vetor, comeco, meio);
        mergeSort(vetor, meio+1, fim);
        merge(vetor, comeco, meio, fim);
    }
}

void merge(int vetor[], int comeco, int meio, int fim) {
    int com1 = comeco, com2 = meio+1, comAux = 0, tam = fim-comeco+1;
    int *vetAux;
    vetAux = (int*)malloc(tam * sizeof(int));

    while(com1 <= meio && com2 <= fim){
        if(vetor[com1] < vetor[com2]) {
            vetAux[comAux] = vetor[com1];
            com1++;
        } else {
            vetAux[comAux] = vetor[com2];
            com2++;
        }
        comAux++;
    }

    while(com1 <= meio){  //Caso ainda haja elementos na primeira metade
        vetAux[comAux] = vetor[com1];
        comAux++;
        com1++;
    }

    while(com2 <= fim) {   //Caso ainda haja elementos na segunda metade
        vetAux[comAux] = vetor[com2];
        comAux++;
        com2++;
    }

    for(comAux = comeco; comAux <= fim; comAux++){    //Move os elementos de volta para o vetor original
        vetor[comAux] = vetAux[comAux-comeco];
    }

    free(vetAux);
}

void intercalar(int *v, int *w, int ini, int meio, int fim){
    int k = 0;

    for(k = ini; k <= fim; k++)
    {
        w[k] = v[k];
    }

    int i = ini;
    int j = meio +1;

    for(k = ini; k <= fim; k++)
    {
        if(i > meio) v[k] = w[j++];
        else if (j > fim) v[k] = w[i++];
        else if (w[i] < w[j]) v[k] = w[i++];
        else v[k] = w[j++];
    }
}

void HeapSort(int *vetor, int n){
    int i, aux;
    for(i = (n-1)/2; i>=0; i--){
        criaHeap(vetor, i, n-1);
    }
    for (i = n-1; i>= 1; i--){
        aux = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = aux;
        criaHeap(vetor, 0, i-1);
    }
}

void criaHeap(int *vetor, int i, int f){
    int aux = vetor[i];
    int j = i*2+1;
    while (j<=f){
        if(j<f){
            if(vetor[j]<vetor[j+1]){
                j = j+1;
            }
        }
        if(aux < vetor[j]){
            vetor[i] = vetor[j];
            i = j;
            j = 2*i+1;
        }else{
            j = f + 1;
        }
    }
    vetor[i] = aux;
}

void QuickSort(int vetor[], int inicio, int fim){
    if(inicio < fim){
        int pivo_indice = particionar(vetor, inicio, fim);

        QuickSort(vetor, inicio, pivo_indice - 1);
        QuickSort(vetor, pivo_indice + 1, fim);
    }
}

int particionar (int vetor[], int inicio, int fim){
    int pivo;

    pivo = vetor[fim];

    while(inicio<fim){
        while(inicio<fim && vetor[inicio] <= pivo)
            inicio++;

        while(inicio<fim && vetor[fim] > pivo)
            fim--;

      //  troca(&vetor[inicio], &vetor[fim]);
    }
    return inicio;
}

void RadixSortLSD(int *vetor, int tamanho){
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




int main()
{
char Seleciona;
int QtdOrd,i, k, count;
double tempoInicial, tempoFinal;

    menu_quantidade();

//while (count <11){  //para coleta de dados dos testes
        tempoInicial = tempo();
        menu_metodo ();   // omitido durante a coleta de dados dos testes
//RadixSortLSD(VET, tamanho);  //para coleta de dados dos testes, só troca a chamada do algoritmo

        tempoFinal = tempo();

    /*     printf("\n\nVetor ordenado: \n\n");
            for(i = 0; i < 11; i++)
            printf("%d  ", VET[i]);
    */
        printf("O tempo gasto em segundos para ordenacao foi de bubble: %lf segundos\n\n",tempoFinal-tempoInicial   );
count++; // }

    system("pause");


    return 0;
}


