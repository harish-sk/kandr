#include <stdio.h>
#define COLUMN_LEN_MAX 80
int main()
{
  char buf[COLUMN_LEN_MAX] = {'\0', };
  int ch, count = 0, tcount = 0, i, j;
  char temp[COLUMN_LEN_MAX] = {'\0', };

  while((ch = getchar()) != EOF){
    buf[count] = ch;
    count++;
    if((ch == '\n') && (count < COLUMN_LEN_MAX - 1)) {
      /* Given line is small and just dump 
	 it no folding required */
      for(i = 0; i < count; i++) {
	putchar(buf[i]);
      }
      count = 0;
    }else if(count >= COLUMN_LEN_MAX - 1) {
      /* Now the given line is 80 characters */
      for(i = 0; i < count; i++) {
	/* store all the space till we hit non white charecters */
	if(buf[i] == ' ' || buf[i] == '\t') {
	  temp[tcount] = buf[i];
	  tcount++;
	}else {
	  /* Putchar all white space before putchar non-white space */
	  if(tcount > 1) {
	    for(j = 0; j < tcount; j++) {
	      putchar(temp[j]);
	    }
	    putchar(buf[i]);
	    tcount = 0;
	  }else {
	    putchar(buf[i]);
	  }
	}
      }
      putchar('\n');
      count = 0;
    }
  }
  return 0;
}
