#include <stdio.h>
#include <stdlib.h>

#define FIB_ARR_SIZE 47

// UNSIGNED_INT_MAX : 4 294 967 296
// 46-е число: 2 971 215 073 ARR[0]...ARR[46]
// 47-е число: 4 807 526 976
// 1 2 3 5 8 13 ...
// 0 1 2 3 4 5

void input_control (unsigned *px) {
	int res;
	res = scanf("%u", px);
	if ((res != 1) || (*px <= 0)) {
		printf("\nInput is wrong!\n");
		abort();
	} 
}

unsigned long long fib(unsigned n) {

	if (n == 0) return 1ull;
	if (n == 1) return 2ull;

	unsigned long long first = 1;
	unsigned long long second = 2;
	unsigned long long fib;

	for (unsigned i = 2; i <= n; ++i) {
		fib = first + second;
		first = second;
		second = fib;
	}

	return (second);
}


void print_converted (unsigned long long x) {
	
	unsigned arr_fib[FIB_ARR_SIZE] = {0};

	unsigned long long fib_max = 1;
	unsigned long long fib_max_next = 1;
	int fib_max_number = -1; // от нуля считаем

	for (int i = 0; (x % fib_max_next) != x; ++i) {
		fib_max_number++;
		fib_max = fib(i);
		fib_max_next = fib(i+1);
	}	

#if 0
	printf("%u %u\n", fib_max, fib_max_number);
#endif

	arr_fib[fib_max_number] = 1;
	
	unsigned long long sum_fib = fib_max;
	
	unsigned long long fib_max_i = 0;

	for (int i = fib_max_number - 2; sum_fib != x; --i) {
		fib_max_i = fib(i);
		sum_fib += fib_max_i;
		if ((sum_fib <= x) && ((arr_fib[i+1] + arr_fib[i]) != 2)) {
			arr_fib[i] = 1;
		} else {
			sum_fib -= fib_max_i;
		}
	}

	for (int i = fib_max_number; i >= 0; --i) {
		printf("%u", arr_fib[i]);

	}
	printf("\n");
}

int main() {
	unsigned x;
	input_control(&x);
	print_converted(x);	
}
