#include <stdio.h>
#include <stdlib.h>
// fib(n) = fib(n - 1) + fib(n - 2)

void input_control(unsigned *pn, unsigned *pbase) {
	unsigned res;
	res = scanf("%u%u", pn, pbase);
	if ((res != 2) || (*pbase ==0)) {
		printf("Input is wrong!\n");
		abort();
	}
}

unsigned long long fib(unsigned n, unsigned base) {
	
	if (n == 0) return 0ull;
	if (n <= 2) return 1ull;

	unsigned long long first = 1;
	unsigned long long second = 1;
	unsigned long long fib;

	for (unsigned i = 3; i <= n; ++i) {
		fib = (first + second) % base;
		first = second % base;
		second = fib % base;
	}

	return (second);
}


int main() {
	unsigned n;
	unsigned base;
	input_control(&n, &base);
	printf("%llu\n", fib(n, base));
}


