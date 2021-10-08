#include <acutest.h>
#include "../src/derivative.c"
#include <math.h>

void test_derivative_sin() {
	for(double x = 0; x < 2 * M_PI; x += 0.1) {
		double dx = derivative(x, sin);

		TEST_CHECK(fabs(dx - cos(x)) < 1e-8);
		TEST_MSG("Expected: %.8f", cos(x));
      TEST_MSG("Produced: %.8f", dx);
	}
}

void test_derivative_cos() {
	for(double x = 0; x < 2 * M_PI; x += 0.1) {
		double dx = derivative(x, cos);

		TEST_CHECK(fabs(dx - (-sin(x))) < 1e-8);
		TEST_MSG("Expected: %.8f", -sin(x));
      TEST_MSG("Produced: %.8f", dx);
	}
}

void test_derivative_sqrt() {
	for(double x = 1; x < 100; x += 0.1) {
		double dx = derivative(x, sqrt);

		double expected_dx = 1 / (2 * sqrt(x));

		TEST_CHECK(fabs(dx - expected_dx) < 1e-6);
		TEST_MSG("Expected: %.8f", expected_dx);
      TEST_MSG("Produced: %.8f", dx);
	}
}

TEST_LIST = {
   { "derivative sin", test_derivative_sin },
   { "derivative cos", test_derivative_cos },
   { "derivative sqrt", test_derivative_sqrt },
   { NULL, NULL }     /* zeroed record marking the end of the list */
};
