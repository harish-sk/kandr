#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF_LEN 1000

void swap(char *a, char *b) {
  char temp;
  temp = *a;
  *a = *b;
  *b = temp;
  return;
}

void reverse(char *s)
{
  int len = strlen(s);
  int i;

  for(i = 0; i < len / 2; i++) {
    swap(&s[i], &s[len-i-1]);
  }
  return;
}
int main()
{
  int ch;
  char buf[MAX_BUF_LEN] = {0,};
  int idx = 0;
  while((ch = getchar()) != EOF) {
    if(ch != '\n') {
      /* Buffer the line */
      buf[idx] = ch;
      idx++;
      if(idx >= MAX_BUF_LEN) {
	printf("ERROR: No buf remaining\n");
	exit(0);
      }
    }else {
      buf[idx] = '\0';
      reverse(buf);
      puts(buf);
      idx = 0;
    }
  }
  return 0;
}
