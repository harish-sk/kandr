#include <stdio.h>

#define SPACE_TO_TAB 4

int main()
{
  int space_count = 0, i;
  int ch;

  while((ch = getchar()) !=EOF) {
    if(ch == ' ') {
      space_count++;
    }else {
      if(space_count > 0) {
	for(i = 0; i< space_count/SPACE_TO_TAB; i++) {
	  putchar('\t');
	}
	for(i = 0; i< space_count % SPACE_TO_TAB; i++) {
	  putchar(' ');
	}
	space_count = 0;
      }
      putchar(ch);
    }
  }
  return 0;
}
