/*Основная часть алгоритма сортировки вставками выглядит следующим образом

void inssort(int *arr, int len) {
  int i;
  for (i = 0; i < len; ++i) {
    int key, pos;
    key = arr[i];
    pos = moveright(arr, key, i);
    arr[pos] = key;
  }
}
*/

int moveright(int *arr, int key, int last) {
  for (int i = 0; i < last; ++i) {
		if (key < arr[i]) {
			for (int j = last; j > i; --j) {
				arr[j] = arr[j-1];
			}
			return i;
		}
	}
	return last;
}
