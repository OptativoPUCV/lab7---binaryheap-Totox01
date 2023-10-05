#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq) {
  if (pq == NULL || pq->size == 0) {
    printf("El montículo está vacío\n");
    return NULL;
  }
  return pq->heapArray[0].data;
}



void heap_push(Heap* pq, void* data, int priority){
  if(pq == NULL){
    printf("El montículo no es válido\n");
    return;
  }
  if (pq->size == pq->capac){
    pq->capac = pq->capac * 2 + 1;
    pq->heapArray = realloc(pq->heapArray, pq->capac * sizeof(heapElem));
    if (pq->heapArray == NULL){
      printf("Error al reasignar memoria para el arreglo del montículo\n");
      return;
    }
  }
}


void heap_pop(Heap* pq){
  
}

Heap* createHeap() {
 
  Heap* heap = (Heap*) malloc(sizeof(Heap));
  if (heap == NULL) {
    printf("Error al reservar memoria para el Heap\n");
    return NULL;
  }
  heap->capac = 3;
  heap->heapArray = (heapElem*) malloc(heap->capac * sizeof(heapElem));
  if (heap->heapArray == NULL) {
    printf("Error al reservar memoria para el arreglo del Heap\n");
    free(heap); 
    return NULL;
  }
  heap->size = 0;
  return heap;
}

