#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct triple {
  int x, y, z;
};

int tcmp(void const *key, void const *elt) {
  struct triple const *lhs = (struct triple const *)key;
  struct triple const *rhs = (struct triple const *)elt;
  if (lhs->x == rhs->x && lhs->y == rhs->y)
    return (lhs->z < rhs->z);
  if (lhs->x == rhs->x)
    return (lhs->y < rhs->y);
  return (lhs->x < rhs->x);
}

typedef int (*cmp_t)(const void *lhs, const void *rhs);

int selstep(void *parr, int eltsize, int n, int last, cmp_t cmp);

int selstep(void *parr, int eltsize, int numelts, int nsorted, cmp_t cmp) {
  	
	char *parr_conv = (char*) parr;

	int arr_conv_size = eltsize * numelts;
	
	int conv_index_nsorted = nsorted * eltsize;
	int min_index = conv_index_nsorted;


	void const *rhs = (void const*) &(parr_conv[conv_index_nsorted]);
	
	for (int i = conv_index_nsorted; i < arr_conv_size; i += eltsize) {
		
		void const *lhs = (void const*) &(parr_conv[i]);
		
		if (cmp(lhs, rhs) == 1) {
			min_index = i;
			rhs = (void const*) &(parr_conv[min_index]);

		}
	}
	
	for (int j = 0; j < eltsize; ++j) {
				
		if (parr_conv[conv_index_nsorted + j] != parr_conv[min_index + j]) {
			char tmp = parr_conv[conv_index_nsorted + j];
			parr_conv[conv_index_nsorted + j] = parr_conv[min_index + j];
			parr_conv[min_index + j] = tmp;
		}
	}
	return 0;
}

int main() {
  int i, res, n, last;
  struct triple *parr;

  res = scanf("%d", &n);
  assert(res == 1);
  assert(n > 2);

  parr = (struct triple *)calloc(n / 3, sizeof(struct triple));

  for (i = 0; i < n / 3; ++i) {
    res = scanf("%d %d %d", &parr[i].x, &parr[i].y, &parr[i].z);
    assert(res == 3);
  }

  res = scanf("%d", &last);
  assert(res == 1);
  assert(last < n);

  selstep(parr, sizeof(struct triple), n / 3, last / 3, &tcmp);

  for (i = 0; i < n / 3; ++i)
    printf("%d %d %d\n", parr[i].x, parr[i].y, parr[i].z);

  free(parr);
  return 0;
}
