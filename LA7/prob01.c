// try using heap
#include <stdio.h>

int main(int argc, char const *argv[]) {
  int n;
  scanf("%d", &n);
  int arr[n];
  float ans[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  ans[0] = arr[0];
  int key, j;
   for (int i = 1; i < n; i++)   //Insertion sort
   {
       key = arr[i];
       j = i-1;
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j--;
       }
       arr[j+1] = key;
       if (i%2 == 0) {
         ans[i] = (float)arr[i/2];
       }
       else{
         ans[i] = ((float)arr[i/2] + (float)arr[i/2 + 1])/2;
       }
   }
   for (int i = 0; i < n; i++) {
     printf("%f\n", ans[i]);
   }
  return 0;
}
