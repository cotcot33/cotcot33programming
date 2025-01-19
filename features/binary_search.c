#include <stdio.h>
#include <stdlib.h>

void input_control(int *plength_arr, int *pstep, int *ptarget) {
	int res;
	res = scanf("%d%d%d", plength_arr, pstep, ptarget);
	if (res != 3) {
		printf("Wrong input.\n");
		abort();

	}
}

void binary_search(int length_arr, int step, int target) {
	int *arr = calloc(length_arr + 1, sizeof(int));
	if (arr == NULL) {
		printf("mERROR\n");
		abort();
	}
	
	int left = 0, mid = 0, right = length_arr - 1;

	for (int i = 0; i < length_arr; ++i) {
		arr[i] = i + step;
		printf("%d ", arr[i]);
	}

	for (;left <= right;) {
		mid = left + (right - left) / 2;
		if (mid == target) {
			printf("\n%d %d\n", mid, arr[mid]);
			return;
		}
		else if (target < mid) right = mid - 1;
		else left = mid + 1;	
	}

	printf("\nнету таково\n");

}

int main() {
	int length_arr, step, target;
	printf("Input length_arr, step, target: ");
	input_control(&length_arr, &step, &target);
	binary_search(length_arr, step, target);
}

