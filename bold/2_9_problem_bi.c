#include <stdio.h>
 
void print_ans(unsigned long long N, unsigned char *arr, unsigned long long bit) {
 unsigned long long arr_size_in_bits = N << 3;
 
 if (bit > (arr_size_in_bits - 1)) {
  for (int i = 0; i < N; ++i) {
   printf("%hhu ", arr[i]);
  }
  return;
 }
 
 unsigned long long index_of_number = bit / 8;
 unsigned long long index_of_bit_in_number = bit % 8;
  
 arr[index_of_number] ^= (1 << index_of_bit_in_number);

 for (int i = 0; i < N; ++i) {
	printf("%hhu ", arr[i]);
 }
 
}
 
int main() {
 unsigned long long N;
 unsigned char x;
 unsigned long long bit;
 
 scanf("%llu", &N);
 
 unsigned char arr[N];
 
 for (int i = 0; i < N; ++i) {
  scanf("%hhu", &x);
  arr[i] = x;
 }
 
 scanf("%llu", &bit);
 
 print_ans(N, arr, bit);
 
}
