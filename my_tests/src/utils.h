#ifndef _MY_TESTS_UTILS_
#define _MY_TESTS_UTILS_

#include <stdint.h>

template<typename Type>
void test_result(Type *y, Type *y_ref, uint64_t nrows)
{
   uint64_t row;
   uint64_t nerrs=0;
   /* Compute with the result to keep the compiler for marking the code as dead */
   for (row=0; row<nrows; row++) {
      double error = y[row] - y_ref[row];
      if (fabs(error) > 0.0000001)  {
         printf("y[%ld]=%.16f != y_ref[%ld]=%.16f  INCORRECT RESULT !!!! \n ", row, y[row], row, y_ref[row]);
         nerrs++;
         if (nerrs == 100) break;
      }
   }
   if (nerrs == 0) {
      printf ("Result ok !!!\n");
      for (row=0; row<5; row++) {
         printf("y[%ld]=%.16f == y_ref[%ld]=%.16f  \n ", row, y[row], row, y_ref[row]);
      }
      printf("...\n");
      for (row=nrows-5; row<nrows; row++) {
         printf("y[%ld]=%.16f == y_ref[%ld]=%.16f  \n ", row, y[row], row, y_ref[row]);
      }
   }
   
}

#endif
