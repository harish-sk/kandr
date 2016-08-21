#include <stdio.h>
#define SPACE_FOR_TAB 4
int main()
{
  int ch, i;
  
  while((ch = getchar()) != EOF) {
    if(ch == '\t') {
      for(i = 0; i < SPACE_FOR_TAB; i++) {
	putchar(' ');
      }
    }else{
      putchar(ch);
    }
  }
  return 0;
}
