#include <acutest.h>
#define TEST_MODE 1
#include "../src/heron.c"
#include <math.h>


void test_heron() {
	double values[3] = {7e-2, 5.0, 6e+23};

	for (int i = 0; i < 3; ++i) {
		double a = values[i];
		double x = heron(a);

		TEST_CHECK(fabs(a*x - 1) < 0.000001);	
	}
	
}

TEST_LIST = {
   { "heron", test_heron },
   { NULL, NULL }     /* zeroed record marking the end of the list */
};
