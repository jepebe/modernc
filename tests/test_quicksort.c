#include <acutest.h>
#include <stdlib.h>

int dbl_cmp(const void* a, const void* b) {
	return *((double*) a) - *((double*) b);
}

void test_quicksort() {
	double values[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

	qsort(&values, 10, sizeof(double), dbl_cmp);

	for (int i = 0; i < 10 - 1; ++i) {
		TEST_CHECK(values[i] < values[i + 1]);
	}
}

TEST_LIST = {
   { "quicksort", test_quicksort },
   { NULL, NULL }     /* zeroed record marking the end of the list */
};
