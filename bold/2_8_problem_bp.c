#include <stdio.h>

void print_bits(unsigned long long int x) {
	
	if (x == 0) { printf ("NO\n"); return; } 

	unsigned cntr_high = -1;
	unsigned cntr_low = 0;
	
	char flag = 0;

	for (;x != 0;) {
		if (((x & 1) == 1) && (flag != 1)) {
			flag = 1;
		}
		x >>= 1;
		++cntr_high;
		if (flag != 1) ++cntr_low;
	}
	printf("%u %u\n", cntr_high, cntr_low);
}

int main() {
	unsigned long long x;
	scanf("%llu", &x);
	print_bits(x);
}
