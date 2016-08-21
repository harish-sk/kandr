#include <stdio.h>
#include <stdlib.h>
#define MAX_BUF_LEN 1000
int main()
{
  int buf[MAX_BUF_LEN] = {0,}; /* Holds temp whitespace */
  int idx = 0; /* Indicates end index of buf */
  int ch;  /*Present input ch */
  int len; /* Present line length */


  while((ch = getchar()) != EOF) {
    if(ch == ' ' || ch == '\t') {
      /* Lets start storing it in buf */
      buf[idx] = ch;
      idx++;
      len++;
    }else if (ch == '\n') {
      if(idx > 0) {
	/* There are some previous whitespace */
	/* This condition is matching pattern which is to be removed */
	if(len != idx) {
	  /* Line is not just filled with white space
	     , hence retain the new line */
	  putchar(ch);
	}
	idx = 0;
      }else if(idx == 0) {
	/* There were some non-white charecters before*/
	putchar(ch);
      }
    }else {
      len++;
      if(idx > 0) {
	/* There white space charecters before non-white space */
	/* Patter is matched here and lets dump all the white spaces here */
	int j = 0;
	for(j = 0; j < idx; j++){
	  putchar(buf[j]);
	}
	putchar(ch);
	idx = 0;
      }else if(idx == 0) {
	/* Just put it back */
	putchar(ch);
      }
    }
  }
  return 0;
}
