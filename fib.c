#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

unsigned long long int fibCache_r[MAX];
unsigned long long int fibCache_i[MAX];

unsigned long long int fib_r_core(unsigned long long int n) {
   if (n <= 1) 
      return n;

   return fib_r_core(n - 1) + fib_r_core(n - 2);
}

unsigned long long int fib_i_core(int n) {
   if (n <= 1)
      return n;

   unsigned long long int a = 0;
   unsigned long long int b = 1;

   for (int i = 2; i <= n; i++) {
      unsigned long long int fib = a + b;
      a = b;
      b = fib;
   }
   return b;
}

unsigned long long int fib_r(unsigned long long int n) {
   if (fibCache_r[n] != -1)
      return fibCache_r[n];
   
   fibCache_r[n] = fib_r_core(n);

   return fibCache_r[n];
}
unsigned long long int fib_i(int n) {
   if (fibCache_i[n] != -1)
      return fibCache_i[n];

   fibCache_i[n] = fib_i_core(n);

   return fibCache_i[n];
}

int main(int argc, char *argv[]) {

   if (argc != 3 || argv[2][0] != 'r' && argv[2][0] != 'i') {
      printf("Invalid Input\n");
      return 0;
   }

   int num = atoi(argv[1]) - 1;

   for (int i = 0; i <= num; i++) {
      fibCache_r[i] = -1;
      fibCache_i[i] = -1;
   }
   
   unsigned long long int result = 0;

   if (argv[2][0] == 'r') {
      result = fib_r(num);
   }
   else {
      result = fib_i(num);
   }

   printf("%lld\n", result);
   return 0;
}