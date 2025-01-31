//Danilo Rodrigues Parolin
//RA: 12325951
//08 - APS Ordenação e Pesquisa

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void bubbleSort(int arr[], int tamanho) {
    int troca;
    for (int i = 0; i < tamanho - 1; i++) {
        troca = 0;
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                troca = 1;
            }
        }
        if (troca == 0) break;
    }
}


void selectionSort(int arr[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < tamanho; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}


void insertionSort(int arr[], int tamanho) {
    for (int i = 1; i < tamanho; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}


void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = (low - 1);
        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        int pi = i + 1;

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int swap = arr[i];
        arr[i] = arr[largest];
        arr[largest] = swap;

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}


void gerarVetorAleatorio(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        arr[i] = rand() % (tamanho * 10); 
    }
}


void copiarVetor(int arr[], int arrCopy[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        arrCopy[i] = arr[i];
    }
}


double medirTempo(void (*func)(int[], int), int arr[], int tamanho) {
    clock_t start, end;
    start = clock();
    func(arr, tamanho);
    end = clock();
    return ((double) (end - start)) / CLOCKS_PER_SEC;
}


double medirTempoRecursivo(void (*func)(int[], int, int), int arr[], int low, int high) {
    clock_t start, end;
    start = clock();
    func(arr, low, high);
    end = clock();
    return ((double) (end - start)) / CLOCKS_PER_SEC;
}

int main() {
    int tamanho = 100000;
    int *arr = (int *)malloc(tamanho * sizeof(int));
    int *arrCopy = (int *)malloc(tamanho * sizeof(int));
    double tempos[6];
    
    gerarVetorAleatorio(arr, tamanho);


    copiarVetor(arr, arrCopy, tamanho);
    printf("Medindo tempo do Bubble Sort...\n");
    tempos[0] = medirTempo(bubbleSort, arrCopy, tamanho);
    
    copiarVetor(arr, arrCopy, tamanho);
    printf("Medindo tempo do Selection Sort...\n");
    tempos[1] = medirTempo(selectionSort, arrCopy, tamanho);
    
    copiarVetor(arr, arrCopy, tamanho);
    printf("Medindo tempo do Insertion Sort...\n");
    tempos[2] = medirTempo(insertionSort, arrCopy, tamanho);

    copiarVetor(arr, arrCopy, tamanho);
    printf("Medindo tempo do Merge Sort...\n");
    tempos[3] = medirTempoRecursivo(mergeSort, arrCopy, 0, tamanho - 1);
    
    copiarVetor(arr, arrCopy, tamanho);
    printf("Medindo tempo do Quick Sort...\n");
    tempos[4] = medirTempoRecursivo(quickSort, arrCopy, 0, tamanho - 1);
    
    copiarVetor(arr, arrCopy, tamanho);
    printf("Medindo tempo do Heap Sort...\n");
    tempos[5] = medirTempo(heapSort, arrCopy, tamanho);


    printf("\nTempos de execucao (em segundos):\n");
    printf("Bubble Sort: %.5f\n", tempos[0]);
    printf("Selection Sort: %.5f\n", tempos[1]);
    printf("Insertion Sort: %.5f\n", tempos[2]);
    printf("Merge Sort: %.5f\n", tempos[3]);
    printf("Quick Sort: %.5f\n", tempos[4]);
    printf("Heap Sort: %.5f\n", tempos[5]);


    char *nomes[6] = {"Bubble Sort", "Selection Sort", "Insertion Sort", "Merge Sort", "Quick Sort", "Heap Sort"};
    for (int i = 0; i < 6 - 1; i++) {
        for (int j = 0; j < 6 - i - 1; j++) {
            if (tempos[j] > tempos[j + 1]) {
                double temp = tempos[j];
                tempos[j] = tempos[j + 1];
                tempos[j + 1] = temp;

                char *tempNome = nomes[j];
                nomes[j] = nomes[j + 1];
                nomes[j + 1] = tempNome;
            }
        }
    }

    printf("\nRanking dos algoritmos (do mais rapido para o mais lento):\n");
    for (int i = 0; i < 6; i++) {
        printf("%d. %s: %.5f segundos\n", i + 1, nomes[i], tempos[i]);
    }


    free(arr);
    free(arrCopy);

    return 0;
}