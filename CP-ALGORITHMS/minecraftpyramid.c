#include <stdio.h>
#include <math.h>

// Number of blocks in a minecraft pyramid

int main(void){
  int levels = 0;
  int calc = 0;
  int sum = 0;

  printf("Number of levels: ");
  scanf(" %d", &levels);

  for(int n = 1; n <= levels; n++){
      calc = 4*pow(n,2);
      printf("\n%d", calc);
      sum = sum + calc;
  }

  printf("\n\nSum: %d", sum);
  return 0;
}
