#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int (*cmp_t)(void const *key, void const *elt);

void *cbsearch(void const *key, void const *base, int num, int size, cmp_t cmp);
void *cbsearch(void const *key, void const *base, int num, int size, cmp_t cmp) {

	char const *base_conv = (char const*)base;
	
	int left = 0;
	int right = size * (num - 1);
	int mid;

	void const *lhs = key;
	void const *rhs;

	for (;left <= right;) {
		mid = left + ((right - left) / (2 * size)) * size;
		rhs = (void const*)&base_conv[mid];
		int res = cmp(lhs, rhs);
		if (res > 0) left = mid + size;
		if (res < 0) right = mid - size;
		if (res == 0) return (void*)&base_conv[mid];
	}

	return NULL;	
}	

struct triple {
  int x, y, z;
};

int tcmp(void const *key, void const *elt) {
  struct triple const *lhs = (struct triple const *)key;
  struct triple const *rhs = (struct triple const *)elt;
  return (lhs->y - rhs->y);
}

int main() {
  int i, res, n, last;
  struct triple found = {-1, -1, -1};
  struct triple *parr, *answ;

  res = scanf("%d", &n);
  assert(res == 1);
  assert(n > 2);

  parr = (struct triple *)calloc(n / 3, sizeof(struct triple));

  for (i = 0; i < n / 3; ++i) {
    res = scanf("%d %d %d", &parr[i].x, &parr[i].y, &parr[i].z);
    assert(res == 3);
    if ((i == n / 7) && ((i % 10) != 0))
      found = parr[i];
  }

  answ = (struct triple *)cbsearch(&found, parr, n / 3, sizeof(found), &tcmp);

  if (!answ || (answ == (struct triple *)(parr + n / 3))) {
    printf("0\n");
    return 0;
  }

  printf("%d %d %d\n", answ->x, answ->y, answ->z);

  free(parr);
  return 0;
}
