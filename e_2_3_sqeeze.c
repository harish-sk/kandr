#include <stdio.h>
#include <string.h>

void sqeeze(const char *s1, char *s2);
int main()
{
  char s1[10] = "hello";
  char *s2 = "world";

  printf("Before Sqeeze s1 is %s\n", s1);

  sqeeze(s1, s2);
  
  printf("After Sqeeze s1 is %s\n", s1);

  return 0;
}
void sqeeze(const char *s1, char *s2)
{
  int i, j;
  int k = 0;
  for(i = 0; i < strlen(s1); i++) {
    for(j = 0; j < strlen(s2); j++) {
      if(s[i] == s[j]){
	break;
      }
    }
    if(j == strlen(s2)) {
      s[k++] = s[i];
    }
  }
}
