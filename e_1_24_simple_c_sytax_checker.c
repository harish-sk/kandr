#include <stdio.h>
int main()
{
  int ch = 0, pch = 0;
  int round_count = 0;
  int square_count = 0;
  int flower_count = 0;
  int comment_count = 0;

  while((ch = getchar()) != EOF) {
    if(ch == '(') {
      round_count++;
    }else if(ch == '[') {
      square_count++;
    }else if(ch == '{') {
      flower_count++;
    }else if(ch == '*' && pch == '/') {
      comment_count++;
    }else if(ch == ')') {
      round_count--;
    }else if(ch == ']') {
      square_count--;
    }else if(ch == '}') {
      flower_count--;
    }else if(ch == '/' && pch == '*') {
      comment_count--;
    }
    pch = ch;
  }
  if(round_count != 0) {
    printf("Syntax Error: Unbalanced Round brackets\n");
  }
  if(square_count != 0) {
    printf("Syntax Error: Unbalanced Square brackets\n");
  }
  if(flower_count != 0) {
    printf("Syntax Error: Unbalanced Flower brackets\n");
  }
  if(comment_count != 0) {
    printf("Syntax Error: Unbalanced Comment\n");
  }
  return 0;
}
