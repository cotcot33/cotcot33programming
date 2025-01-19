#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_SIZE 1000

void control_input(unsigned long long *pnum, unsigned *pbase) {
	int res;
	res = scanf("%llu%u", pnum, pbase);
	if ((res != 2) || ((*pbase < 2) || (*pbase > 10))) {
		printf("Input is wrong!\n");
		abort();
	}
	if (*pnum == 0) {
		printf("0\n");
		return;
	}
}

void print_converted(unsigned long long num, unsigned base) {
	unsigned number[MAX_SIZE] = {0};
	int index = 0;
	for (int q; num != 0; ++index) {
		q = num % base;
		num = num / base;
		number[index] = q;
	}
	for (int start = 0, end = index - 1, tmp; start < end; ++start, --end) {
		tmp = number[start];
		number[start] = number[end];
		number[end] = tmp;
	}
	for (int i = 0; i < index; ++i) {
		printf("%d", number[i]);
	}
	printf("\n");
}

int main() {
	unsigned long long num;
	unsigned base;
#if 0	
	printf("Input number (number >= 0) and base (base <= 10): ");
#endif	
	control_input(&num, &base);
	print_converted(num, base);
}

