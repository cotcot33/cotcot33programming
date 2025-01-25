#include <stdio.h>

long long min_pos(unsigned long long N, long long *arr, unsigned long long pos) {
	long long min = arr[pos];
	unsigned long long minpos = pos;
	for (long long i = pos; i < N; ++i) {
		if (arr[i] < min) {
			min = arr[i];
			minpos = i;
		}
	}
	return minpos;
}

void sse_one_iter(unsigned long long N, long long *arr, unsigned long long pos) {
	long long minpos = min_pos(N, arr, pos);
	long long tmp = arr[pos];
	arr[pos] = arr[minpos];
	arr[minpos] = tmp;
	for (long long i = 0; i < N; ++i) printf("%lld ", arr[i]);
}

int main() {
	unsigned long long N;
	scanf("%llu", &N);
	long long arr[N];
	long long x;
	unsigned long long pos;
	for (long long i = 0; i < N; ++i) {
		scanf("%lld", &x);
		arr[i] = x;
	}
	scanf("%llu", &pos);
	sse_one_iter(N, arr, pos);
}
