#include <acutest.h>
#include <stdlib.h>
#include <time.h>
#include "../src/mergesort.c"


int double_comparator(void* a, void* b) {
	double da = *((double*) a);
	double db = *((double*) b);
	
	if (da < db) return -1;
	else if (da > db) return 1;
	else return 0;
}

void test_mergesort() {
	size_t count = 9999;
	double values[count];

	srand(time(NULL));
	for (size_t i = 0; i < count; ++i) {
		values[i] = rand() / 100.0;
	}

	merge_sort(values, count, sizeof(double), double_comparator);

	for (size_t i = 0; i < count - 1; ++i) {
		TEST_CHECK(values[i] <= values[i + 1]);
		TEST_MSG("Expected: %.4f <= %.4f", values[i], values[i+1]);		
	}
}

TEST_LIST = {
   { "mergesort", test_mergesort },
   { NULL, NULL }     /* zeroed record marking the end of the list */
};
