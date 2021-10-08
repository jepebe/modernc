#include <acutest.h>
#include <math.h>

double bpp(int n) {
     double d = (pow(10, n)/pow(16,n)) * ((4.0/(8 * n + 1)) - ((2.0 / (8 * n + 4))) - 
          ((1.0 / (8 * n + 5))) - ((1.0 / (8 * n + 6))));
     return d;
}


void test_pi() {
     double pi = 0;
     for(int i = 0; i < 10; ++i) {
          pi += bpp(i);
          // printf("%d = %.18f\n", i, bpp(i));
          // printf("%.18f\n", pi);
     }
}

TEST_LIST = {
   { "pi", test_pi },
   { NULL, NULL }     /* zeroed record marking the end of the list */
};
