#include <stdio.h>

/* intenal states to count words */
#define IN 1
#define OUT 0

#define MAX_WORD_LEN 20

int main()
{
  int count[MAX_WORD_LEN] = {0};
  int c, len = 0, max = 0;
  int state = OUT;
  int i = 0, j = 0;

  while((c = getchar()) != EOF) {
    if(c == ' ' || c == '\t' || c == '\n') {
      if(state == IN && len >= 1 &&
	 len < MAX_WORD_LEN) {
	count[len]++;
	if(count[len] > max) {
	  max = count[len];
	}
      }
      len = 0;
      state = OUT;
    }else if(state == OUT) {
      state = IN;
      len++;
    }else {
      len++;
    }
  }

  printf("\n");
  /* Draws the histogram */
  for(i = max; i >= 1; i--) {
    for(j = 1; j <= MAX_WORD_LEN; j++) {
      if(count[j] > i) {
	printf("  *");
      }else {
	printf("   ");
      }
    }
    printf("\n");
  }
  /* Draws a verticle line */
  for(j = 1; j <= MAX_WORD_LEN; j++) {
    printf("---");
  }
  printf("\n");
  /* Print the counts */
  for(j = 1; j <= MAX_WORD_LEN; j++) {
    printf("%3d", j);
  }
  printf("\n");
	
  return 0;
}
