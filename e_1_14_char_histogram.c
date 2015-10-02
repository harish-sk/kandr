#include <stdio.h>

#define MAX_WORD_LEN 94

int main()
{
  int count[MAX_WORD_LEN] = {0};
  int c, len = 0, max = 0;
  int i = 0, j = 0;

  while((c = getchar()) != EOF) {
    if(c >= 33 && c <= 126) {
      count[c-33]++;
      if(count[c-33] > max) {
	max = count[c-33];
      }
    }
  }

  printf("\n");
  /* Draws the histogram */
  for(i = max; i >= 1; i--) {
    for(j = 1; j <= MAX_WORD_LEN; j++) {
      if(count[j] > i) {
	printf("*");
      }else {
	printf(" ");
      }
    }
    printf("\n");
  }
  /* Draws a verticle line */
  for(j = 1; j <= MAX_WORD_LEN; j++) {
    printf("-");
  }
  printf("\n");
  /* Print the counts */
  for(j = 1; j <= MAX_WORD_LEN; j++) {
    printf("%c", j+33);
  }
  printf("\n");
	
  return 0;
}
