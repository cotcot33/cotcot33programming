#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if 0

void key_swap(int *arr, unsigned key_prew_pos ,unsigned key_pos) {
	int tmp = arr[key_pos];
	arr[key_pos] = arr[key_prew_pos];
	arr[key_prew_pos] = tmp;
}

unsigned partition(int *arr, unsigned low, unsigned high) {

	unsigned low_prew = low;

	int key = arr[low];

	unsigned tmp;
	
	low++;

	for (;low <= high;) {
		
		if (arr[low] <= key) {
			low++;
			continue;
		}
			
		if (arr[high] > key) {
			high--;
			continue;
		}

		tmp = arr[low]; arr[low] = arr[high]; arr[high] = tmp;
		low++;
		high--;
	}

	key_swap(arr, low_prew, high);
	
	return high;
}

void qsort_impl(int *arr, unsigned low, unsigned high) {
  if (low >= high) return;
  unsigned pi = partition(arr, low, high);
  if (pi > low) qsort_impl(arr, low, pi - 1);
  qsort_impl(arr, pi + 1, high);
}

void myqsort(int *arr, unsigned len) {
  qsort_impl(arr, 0u, len - 1);
}

int main () {
	unsigned N;
	scanf("%u", &N);

	int arr[N];
	int x;
	for (int i = 0; i < N; ++i) {
		scanf("%d", &x);
		arr[i] = x;
	}

	for (int i = 0; i < N; ++i)
		printf("%d ", arr[i]);
	printf("\n");

	myqsort(arr, N);

	for (int i = 0; i < N; ++i)
		printf("%d ", arr[i]);
	printf("\n");
}
#endif

void key_shift(int *arr, unsigned key_prew_pos ,unsigned key_pos) {
	int tmp = arr[key_pos];
	arr[key_pos] = arr[key_prew_pos];
	arr[key_prew_pos] = tmp;
}

unsigned partition(int *arr, unsigned low, unsigned high) {

	unsigned low_prew = low;

	int key = arr[low];

	unsigned tmp;
	
	low++;


	for (;low <= high;) {
		
		if (arr[low] <= key) {
			low++;
			continue;
		}
			
		if (arr[high] > key) {
			high--;
			continue;
		}

		tmp = arr[low]; arr[low] = arr[high]; arr[high] = tmp;
		low++;
		high--;
	}

	key_shift(arr, low_prew, high);
	
	return high;
}

void print_fail(int *arr, int *shadow, int n, int i, int pivot) {
  int j;
  printf("\nFAILED!\nSource array: ");
  for (j = 0; j < n; ++j)
    printf("%d ", shadow[j]);
  printf("\nAfter partition (pivot = %d):\n", pivot);
  for (j = 0; j < n; ++j)
    printf("%d ", arr[j]);
  printf("\nLook at position %d, here something gone wrong\n", i);
}

int main() {
  int res, answ, n, i, pivot;
  int *parr, *shadow;

  res = scanf("%d", &n);
  assert(res == 1);
  assert(n > 0);

  parr = calloc(n, sizeof(int));
  assert(parr);

  shadow = calloc(n, sizeof(int));
  assert(shadow);

  for (i = 0; i < n; ++i) {
    res = scanf("%d", parr + i);
    shadow[i] = parr[i];
    assert(res == 1);
  }
  
  pivot = parr[0];

  answ = partition(parr, 0, n - 1);

#if defined(VISUAL)
  for (i = 0; i < n; ++i)
    printf("%d ", shadow[i]);
  printf("\n");
  for (i = 0; i < n; ++i)
    printf("%d ", parr[i]);
  printf("\n");
#endif

  for (i = 0; i < n; ++i) {
    if ((i < answ && parr[i] > pivot) || (i > answ && parr[i] < pivot))
      print_fail(parr, shadow, n, i, pivot);
  }
  
  printf("%d\n", answ);

  free(parr);
}

