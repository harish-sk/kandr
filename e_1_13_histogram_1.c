#include <stdio.h>

/* intenal states to count words */
#define IN 1
#define OUT 0

#define MAX_WORD_LEN 20

int main()
{
  int count[MAX_WORD_LEN] = {0};
  int c, len = 0;
  int state = OUT;
  int i = 0, j = 0;

  while((c = getchar()) != EOF) {
    if(c == ' ' || c == '\t' || c == '\n') {
      if(state == IN && len >= 1 &&
	 len < MAX_WORD_LEN) {
	count[len]++;
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
  for(i = 1; i < MAX_WORD_LEN; i++) {
    printf("%2d | ", i);
    for(j = 0; j < count[i]; j++)
      printf("*");
    printf("\n");
  }
	
  return 0;
}
