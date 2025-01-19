/*Вам на вход приходят числитель и знаменатель дроби.
Ваша задача: написать программу выдающую на стандартный вывод представление цепной дробью.*/

#include <stdio.h>
#include <stdlib.h>

void read_input(long long *pn, long long *pm) {
	unsigned res;
	res = scanf("%lld%lld", pn, pm);
	if (res != 2) {
		printf("Wrong input!\n");
		abort();
	}
	if (*pm == 0) {
		printf("Denominator is 0!\n");
		abort();
	}	
}

long long iabs(long long x) {
	return (x < 0 ? -x : x); 
}

long long e_mod(long long x, long long y) {
	int r;
	r = x % y;
	if (r < 0) {
		r += iabs(y);
	}	
	return r; 
}

long long gcd(long long x, long long y) {
	int tmp;
	while ( (e_mod(x, y)) != 0 ) {
		tmp = x;
		x = y;
		y = e_mod(tmp, y);
	}
	if (y < 0) {
		return iabs(y);
	}
	return y;	
}


void print_converted(long long num, long long denom) {
	// 1 найти НОД чтобы сократить дробь
	long long gcd_num_denom = gcd(num, denom);
	num = num / gcd_num_denom;
	denom = denom / gcd_num_denom;

	long long int_part;
	long long tmp;

	for (; denom != 0;) {
		int_part = num / denom;
		tmp = num;
		num = denom;
		denom = tmp % denom;
		printf("%lld ", int_part); 
	}
}

int main() {
	long long n, m;
#if 0	
	printf("Input n and m (m != 0): ");
#endif
	read_input(&n, &m);
	print_converted(n, m);
}

