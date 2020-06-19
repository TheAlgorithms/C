#include <stdio.h>

void swap(int* x, int* y);
void max_heapify(int* a, int i, int n);
void heapsort(int* a, int n);
void build_maxheap(int* a, int n);

void swap(int* x, int* y) {
  const int temp = *x;
  *x = *y;
  *y = temp;
}

void heapify(int* a, int i, int n) {
  int largest = i;
  const int l = 2 * i + 1;
  const int r = 2 * i + 2;

  if (l < n && a[l] > a[largest])
    largest = l;

  if (r < n && a[r] > a[largest])
    largest = r;

  if (largest != i) {
    swap(&a[i], &a[largest]);
    heapify(a, n, largest);
  }
}

void heapsort(int* a, int n) {
  for (int i = n - 1; i >= 0; --i) {
    swap(&a[0], &a[i]);
    heapify(a, 0, i);
  }
}

void build_maxheap(int* a, int n) {
  for (int i = n / 2 - 1; i >= 0; --i) {
    heapify(a, i, n);
  }
}

int main() {
  int n;
  printf("Enter number of elements of array\n");
  scanf("%d", &n);
  int a[20];
  for (int i = 0; i < n; ++i) {
    printf("Enter Element %d\n", i);
    scanf("%d", a + i);
  }

  build_maxheap(a, n);
  heapsort(a, n);
  printf("Sorted Output\n");
  for (int i = 0; i < n; ++i) {
    printf("%d\n", a[i]);
  }

  getchar();
}
