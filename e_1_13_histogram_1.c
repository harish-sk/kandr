#include <stdio.h>

#define IN 1
#define OUT 0

#define MAX_WORD_LEN 20

int main()
{
	int count[MAX_WORD_LEN] = {0};
	int c, steps = 0;
	int state = OUT, len = 0, max_count = 1, i = 0, j = 0;
	int max_column_width = 1;

	while((c = getchar()) != EOF) {
		if((c == ' ') || (c == '\t') || (c == '\n')) {
			if((state == IN) &&
				(len >= 1) && (len < MAX_WORD_LEN)) {
				count[len]++;
				max_count = ((count[len] > max_count)?count[len]:max_count);
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
	
	return 0;
}
