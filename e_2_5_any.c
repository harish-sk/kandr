#include <stdio.h>
#include <string.h>

int any(const char *s1, const char *s2);
int main()
{
  char *s1 = "hello";
  char *s2 = "world";
  int idx;

  idx = any(s1, s2);
  
  printf("First character matching %c is at %d\n", s1[idx], idx);

  return 0;
}
int any(const char *s1, const char *s2)
{
  int i, j;
  int k = 0;
  for(i = 0; i < strlen(s1); i++) {
    for(j = 0; j < strlen(s2); j++) {
      if(s1[i] == s2[j])
	break;
    }
    if(j != strlen(s2)) {
      break;
    }
  }
  return i;
}
