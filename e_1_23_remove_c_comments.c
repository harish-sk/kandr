#include <stdio.h>

enum com_type_t { NOT_COMMENT = 0,
		  COMMENT_SINGLE_LINE = 1,
		  COMMENT_MULTI_LINE = 2};

#define is_not_com() (com == NOT_COMMENT)

int main()
{
  int is_str = 0;
  int ch = -1, pch = -1;
  enum com_type_t com = NOT_COMMENT;
  
  while((ch = getchar()) != EOF) {
    if(ch == '"' && is_not_com()){
      is_str = ~is_str;
    }
    if(!is_str &&
       is_not_com() &&
       ch == '/' &&
       pch == '/') {
      com = COMMENT_SINGLE_LINE;
    }else if(!is_str &&
	     is_not_com() &&
	     ch == '*' &&
	     pch == '/') {
      com = COMMENT_MULTI_LINE;
    }
    if(is_not_com() && pch != -1) {
      putchar(pch);
    }
    if(!is_str &&
	     com == COMMENT_SINGLE_LINE &&
	     ch == '\n') {
      putchar(' ');
      com = NOT_COMMENT;
    }else if(!is_str &&
	     com == COMMENT_MULTI_LINE &&
	     ch == '/' &&
	     pch == '*') {
      ch = ' ';
      com = NOT_COMMENT;
    }
    pch = ch;
  }
  
}
