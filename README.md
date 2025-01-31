# Ordenacao-e-Pesquisa
Projeto para comparar a ordenação de seis algoritmos clássicos em linguagem C.

Este projeto implementa e compara o desempenho de seis algoritmos de ordenação clássicos em C: Bubble Sort, Selection Sort, Insertion Sort, Merge Sort, Quick Sort, e Heap Sort. O objetivo principal é medir o tempo de execução de cada algoritmo em uma lista de números aleatórios e classificá-los em ordem crescente de tempo de execução.

Funcionalidades:

1 - Algoritmos de Ordenação:
Bubble Sort: Um algoritmo simples que compara e troca elementos adjacentes até que a lista esteja ordenada.
Selection Sort: Ordena a lista selecionando repetidamente o menor (ou maior) elemento e colocando-o na posição correta.
Insertion Sort: Insere elementos na posição correta de uma lista parcialmente ordenada.
Merge Sort: Algoritmo de ordenação baseado em divisão e conquista, que divide a lista recursivamente e a reconstrói ordenada.
Quick Sort: Algoritmo de ordenação eficiente baseado em partição, dividindo a lista em duas sublistas e ordenando-as de forma recursiva.
Heap Sort: Utiliza uma estrutura de heap para ordenar a lista, realizando trocas para garantir a ordenação correta.

2 - Medição de Desempenho:
O tempo de execução de cada algoritmo é medido utilizando a função clock() para calcular o tempo passado durante a execução.
A comparação dos tempos de execução é feita para determinar o algoritmo mais rápido e o mais lento.
Geração de Vetor Aleatório:
A função gerarVetorAleatorio cria um vetor de números aleatórios que é utilizado para a ordenação.

3 - Cópia de Vetores:
Para evitar alterações nos vetores durante a execução de múltiplos algoritmos, a função copiarVetor copia o vetor original antes de cada execução de algoritmo.

4 - Exibição dos Resultados:
Os tempos de execução dos algoritmos são impressos no console, seguidos do ranking dos algoritmos, do mais rápido ao mais lento, baseado no tempo de execução.

Estrutura do Código:
Funções de Ordenação: Implementação dos seis algoritmos de ordenação, cada um com uma abordagem distinta.
Funções de Medição de Tempo: Funções para medir o tempo de execução dos algoritmos tanto em versões iterativas quanto recursivas.
Funções Auxiliares: Funções para gerar vetores aleatórios, copiar vetores e organizar os resultados.
