#include <math.h>
#include <stdio.h>

#define NUM 100 //limitation of i

double poisson_recursive(int lam,int i,double initP);
/* long long factorial_iterative(int n); */

int main() {
  int lam;  
  double initP;
  double result[NUM]; //arr that stores the probability results.
  printf("specifiy a lambda:\n");
  scanf("%d", &lam);
  if (lam <= 0) {
    printf("bro uses a bad lambda\n");
    return 1;
  }
  
  // poisson(recursion)
  initP = exp(-lam); //starts from i=0
  
  for (int i=0; i<NUM; i++) {
    result[i] = poisson_recursive(lam, i, initP);
    
    if(result[i] < 1e-8) {
      printf("probability(X = %d) is too small!",i);
      break;
    }
    printf("probability(X = %d) = %.8f\n",i, result[i]);    
  }
  
  return 0;
}

double poisson_recursive(int lam, int i, double initP) {  
  double prevResult;
  
  if (i == 0)
    return initP;
  
  prevResult = poisson_recursive(lam, i-1, initP);
  
  return (double)lam/i * prevResult;
}
/* /\* */
/*  * this funcion is provided by Deepseek, lol. */
/*  *\/ */
/* long long factorial_iterative(int n) { */
/*     if (n < 0) {         */
/*         return -1;  */
/*     } */
/*     if (n == 0 || n == 1) { */
/*         return 1; */
/*     } */
    
/*     int result = 1; */
/*     for (int i = 2; i <= n; i++) { */
/*         result *= i; */
/*     } */
/*     return result; */
/* } */
