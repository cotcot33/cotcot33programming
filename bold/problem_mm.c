#include <stdio.h>

void min_max(unsigned long long N, long long *arr) {
	if (N == 1) {
		printf("%llu\n", arr[0]);
		return;
	}

	unsigned char flag = 0;
	long long min = arr[0];
	long long max = arr[0];
	
	for (int i = 1; i < N; ++i) {
		if (arr[i] > max) { 
			max = arr[i];
			flag = 1;
		}
		if (arr[i] < min) {
			min = arr[i];
			flag = 1;
		}
	}
	if (flag) {
		printf("%lld %lld\n", min, max);
		return;
	}
	printf("0 0\n");
}

int main() { 
	
	unsigned long long N;
	scanf("%llu", &N);

	if (N == 0) {
		printf("0 0\n");
		return 0;
	}

 	long long arr[N];
	long long x;
	
	for (int i = 0; i < N; ++i) {
    	scanf("%llu", &x);
        arr[i] = x;
    }

	min_max(N, arr);
}
