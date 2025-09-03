#include <math.h>
#include <stdio.h>

#define NUM 500 //limitation of i

double poisson_iterative(int lam,int i,double tmp);
long long factorial_iterative(int n);

int main() {
  int lam;
  int i = 5;
  double result;  
  printf("specifiy a lambda:\n");
  scanf("%d", &lam);

  // poisson 
  result = (exp(-lam) * (pow(lam, i)) ) / factorial_iterative(i);  
  
  while(i < NUM) {
    if(result < 1e-8) {
      printf("probability(X = %d) is too small!", i);
      break;
    } 
      printf("probability(X = %d) = %.8f\n",i, result);    
      i++;
      result = poisson_iterative(lam, i, result);
    
  }
  return 0;
}

double poisson_iterative(int lam, int i, double tmp) {    
  return (double)lam/i * tmp;
}
/*
 * this funcion is provided by Deepseek, lol.
 */
long long factorial_iterative(int n) {
    if (n < 0) {        
        return -1; 
    }
    if (n == 0 || n == 1) {
        return 1;
    }
    
    int result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}
