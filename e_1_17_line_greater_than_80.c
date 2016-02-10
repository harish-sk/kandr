#include <stdio.h>

#define MAX_LINE 256

void print_line(int *p, int len)
{
  int i = 0;
  while(i < len)
    printf("%c", p[i++]);
  printf("\n");
}

int main()
{
  int c, len = 0;
  int buf_line[MAX_LINE];

  while((c = getc(stdin)) != EOF) {
    if(c == '\n') {
      if(len >= 80) {
	print_line(buf_line, len);
      }
      len = 0;
    }else {
      if(len < MAX_LINE)
	buf_line[len++] = c;
    }
  }
}
