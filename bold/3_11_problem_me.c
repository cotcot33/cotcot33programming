#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int majority_element(const int *parr, int len) {
	
	int cntr_confirm = 0;
	int cntr = 0;
	int max;

	for (int i = 0; i < len; ++i) {
    if (cntr == 0) {
			max = parr[i];
		}

		if (max == parr[i]) cntr++;
		else if (cntr != 0) cntr--;
	}

	for (int i = 0; i < len; ++i) {
		if (parr[i] == max) 
			cntr_confirm++;
	}

	if (cntr_confirm > (len / 2)) return max;
	
	return -1;
}



int main() {
  int res, n, i, answ;
  int *arr;

  res = scanf("%d", &n);
  assert(res == 1);
  assert(n > 0);

  arr = calloc(n, sizeof(int));
  for (i = 0; i < n; ++i) {
    res = scanf("%d", arr + i);
    assert(res == 1);
  }

  answ = majority_element(arr, n);

  printf("%d\n", answ);

  free(arr);
  return 0;
}
