//*********Very Very Important

#include <stdio.h>
#include <limits.h>

struct minHeapNode{
  int element;
  int i;
  int j;
};

void swap(struct minHeapNode *x, struct minHeapNode *y)
{
    struct minHeapNode temp = *x;
    *x = *y;
    *y = temp;
}

void heapify(int i, int n, struct minHeapNode minHeap[n]){
  int l = 2*i + 1;
  int r = 2*i + 2;
  int smallest = i;
  if (l < n && minHeap[l].element < minHeap[smallest].element) {
    smallest = l;
  }
  if (r < n && minHeap[r].element < minHeap[smallest].element) {
    smallest = r;
  }
  if (smallest != i) {
    swap(&minHeap[i],&minHeap[smallest]);
    heapify(smallest, n, minHeap);
  }
}

void createHeap(int n, struct minHeapNode minHeap[n]){
  int i = ((n-1) - 1)/2;
  while (i>=0) {
    heapify(i, n, minHeap);   //for each subtree
    i--;
  }
}

void merge(int n, int k, int cars[n][k], struct minHeapNode minHeap[n], int output[n*k]){
  for (int x = 0; x < n; x++) {
    minHeap[x].element = cars[x][0];
    minHeap[x].i = x;
    minHeap[x].j = 1;
  }
  createHeap(n, minHeap);
  for (int i = 0; i < n*k; i++) {
    output[i] = minHeap[0].element;
    if (minHeap[0].j < k) {
      minHeap[0].element = cars[minHeap[0].i][minHeap[0].j];
      minHeap[0].j += 1;
    }
    else{
      minHeap[0].element = INT_MAX;
    }
    heapify(0, n, minHeap);
  }

}

int main(int argc, char const *argv[]) {
  int n,k;
  scanf("%d %d", &n, &k);
  int cars[n][k];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      scanf("%d", &cars[i][j]);
    }
  }
  int output[n*k];
  struct minHeapNode minHeap[n];
  merge(n,k,cars,minHeap,output);
  for (int i = 0; i < n*k; i++) {
    printf("%d ", output[i]);
  }
  printf("\n");
  return 0;
}
