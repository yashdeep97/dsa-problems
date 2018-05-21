#include <stdio.h>
#include <limits.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void insert(int n, int heap[n][2], int x, int y){
  heap[n][0] = x;
  heap[n][1] = y;
  while (n != 0 && heap[(n-1)/2][1] > heap[n][1]) {
      swap(&heap[(n-1)/2][1], &heap[n][1]);
      swap(&heap[(n-1)/2][0], &heap[n][0]);
      n = (n-1)/2;
  }
  return;
}

void heapify(int i, int n, int minHeap[n][2]){
  int l = 2*i + 1;
  int r = 2*i + 2;
  int smallest = i;
  if (l < n && minHeap[l][1] < minHeap[smallest][1]) {
    smallest = l;
  }
  if (r < n && minHeap[r][1] < minHeap[smallest][1]) {
    smallest = r;
  }
  if (smallest != i) {
    swap(&minHeap[i][0],&minHeap[smallest][0]);
    swap(&minHeap[i][1],&minHeap[smallest][1]);
    heapify(smallest, n, minHeap);
  }
}

int release(int n, int heap[n][2]){
    if (n == 1) {
        return heap[0][0];
    }
    int min = heap[0][0];
    heap[0][1] = INT_MAX;
    heapify(0, n, heap);
    return min;
}

int main(int argc, char const *argv[]) {
  int n;
  scanf("%d", &n);
  int times[n][2];
  for (int i = 0; i < n; i++) {
    scanf("%d", &times[i][0]);
    scanf("%d", &times[i][1]);
  }
  int heap[n][2];
  int currentTime = 0;
  int currentSize = 0;
  int ans = 0;
  int index;
  for (int i = 0; i < n; i++) {
      while (currentTime < times[i][0]) {
        index = release(currentSize, heap);
        currentTime += times[index][1];
        ans += currentTime-times[index][0];
        currentSize--;
      }
      insert(currentSize,heap,times[i][0],times[i][1]);
      currentSize++;
  }
  while (currentSize > 0) {
    index = release(currentSize, heap);
    currentTime += times[index][1];
    ans += currentTime-times[index][0];
    currentSize--;
  }
  printf("%d\n", ans/n);
  return 0;
}
